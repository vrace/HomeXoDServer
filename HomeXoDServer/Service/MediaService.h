#ifndef MEDIA_SERVICE_H
#define MEDIA_SERVICE_H

#include <vector>
#include "../Model/Media.h"

class MediaService
{
public:
	MediaService();

	const std::vector<Media>& GetMediaList();

private:
	std::wstring GetMediaPath();
	void SearchMediaFile(const std::wstring &path, const std::wstring &relative, std::vector<std::wstring> &files);
	bool IsMediaFile(const std::wstring &name);

private:
	std::vector<Media> _mediaList;
};

#endif
