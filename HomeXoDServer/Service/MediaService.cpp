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
	std::vector<std::wstring> files;
	SearchMediaFile(GetMediaPath(), L"", files);

	_mediaList.clear();
	for (std::vector<std::wstring>::iterator it = files.begin(); it != files.end(); ++it)
	{
		const std::wstring &path = *it;
		
		int bytes = WideCharToMultiByte(CP_UTF8, 0, path.c_str(), path.length(), NULL, 0, NULL, NULL);
		
		std::vector<char> buf(bytes + 1, '\0');
		WideCharToMultiByte(CP_UTF8, 0, path.c_str(), path.length(), &buf[0], buf.size(), NULL, NULL);

		std::string name = &buf[0];
		
		Media media;
		media.SetName(name);

		_mediaList.push_back(media);
	}

	return _mediaList;
}

std::wstring MediaService::GetMediaPath()
{
	PWSTR path;
	
	if (SHGetKnownFolderPath(FOLDERID_Downloads, KF_FLAG_DEFAULT, NULL, &path) == S_OK)
	{	
		std::wstring mediaPath = path;
		CoTaskMemFree(path);
		return mediaPath;
	}

	return std::wstring();
}

void MediaService::SearchMediaFile(const std::wstring &path, const std::wstring &relative, std::vector<std::wstring> &files)
{
	HANDLE hf;
	WIN32_FIND_DATA wfd;

	std::wstring term = path + L"\\*";
	hf = FindFirstFile(term.c_str(), &wfd);

	while (hf != INVALID_HANDLE_VALUE)
	{
		if (wcslen(wfd.cFileName) > 0 && wfd.cFileName[0] != L'.')
		{
			std::wstring found = relative + wfd.cFileName;

			if ((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				std::wstring s = path + L"\\" + wfd.cFileName;
				SearchMediaFile(s, found + L"\\", files);
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

bool MediaService::IsMediaFile(const std::wstring &name)
{
	static const std::wstring supportedTypes[] = {
		L".mp4",
		L".mkv",
		L".avi",
		L".rm",
		L".rmvb",
		L".divx",
		L".xvid",
	};

	std::wstring::size_type pos = name.rfind('.');
	
	if (pos != std::wstring::npos)
	{
		std::wstring ext = name.substr(pos);
		std::transform(ext.begin(), ext.end(), ext.begin(), (wchar_t (*)(wchar_t))towlower);

		const std::wstring *typesBegin = supportedTypes;
		const std::wstring *typesEnd = supportedTypes + sizeof(supportedTypes) / sizeof(supportedTypes[0]);
		
		if (std::find(typesBegin, typesEnd, ext) != typesEnd)
			return true;
	}

	return false;
}
