#include "MediaService.h"
#include <Windows.h>
#include <ShlObj.h>
#include <string.h>
#include <algorithm>

MediaService::MediaService()
{

}

const std::vector<Media>& MediaService::GetMediaList()
{
	std::vector<std::string> files;
	SearchMediaFile(GetMediaPath(), "", files);

	return _mediaList;
}

std::string MediaService::GetMediaPath()
{
	PWSTR path;
	
	if (SHGetKnownFolderPath(FOLDERID_Downloads, KF_FLAG_DEFAULT, NULL, &path) == S_OK)
	{
		int bytes = WideCharToMultiByte(CP_UTF8, 0, path, wcslen(path), NULL, 0, NULL, NULL);
		std::vector<char> buf(bytes, '\0');
		WideCharToMultiByte(CP_UTF8, 0, path, wcslen(path), &buf[0], buf.size(), NULL, NULL);
		
		CoTaskMemFree(path);
		return std::string(&buf[0], bytes);
	}

	return std::string();
}

void MediaService::SearchMediaFile(const std::string &path, const std::string &relative, std::vector<std::string> &files)
{
	HANDLE hf;
	WIN32_FIND_DATA wfd;

	std::string term = path + "\\*";
	hf = FindFirstFile(term.c_str(), &wfd);

	while (hf != INVALID_HANDLE_VALUE)
	{
		if (strlen(wfd.cFileName) > 0 && wfd.cFileName[0] != '.')
		{
			std::string found = relative + wfd.cFileName;

			if ((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::string s = path + "\\" + wfd.cFileName;
				SearchMediaFile(s, found + "\\", files);
			}
			else
			{
				if (IsMediaFile(found))
					files.push_back(found);
			}
		}

		if (!FindNextFile(hf, &wfd))
		{
			FindClose(hf);
			hf = INVALID_HANDLE_VALUE;
		}
	}
}

bool MediaService::IsMediaFile(const std::string &name)
{
	static const std::string supportedTypes[] = {
		".mp4",
		".mkv",
		".avi",
		".rm",
		".rmvb",
		".divx",
		".xvid",
	};

	std::string::size_type pos = name.rfind('.');
	
	if (pos != std::string::npos)
	{
		std::string ext = name.substr(pos);
		std::transform(ext.begin(), ext.end(), ext.begin(), (char (*)(char))tolower);

		const std::string *typesBegin = supportedTypes;
		const std::string *typesEnd = supportedTypes + sizeof(supportedTypes) / sizeof(supportedTypes[0]);
		
		if (std::find(typesBegin, typesEnd, ext) != typesEnd)
			return true;
	}

	return false;
}
