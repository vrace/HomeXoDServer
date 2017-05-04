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
	std::vector<Media> _mediaList;
};

#endif
