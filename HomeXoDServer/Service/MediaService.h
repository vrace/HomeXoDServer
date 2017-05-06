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
	std::string GetMediaPath();
	void SearchMediaFile(const std::string &path, const std::string &relative, std::vector<std::string> &files);
	bool IsMediaFile(const std::string &name);

private:
	std::vector<Media> _mediaList;
};

#endif
