#include "MediaService.h"

MediaService::MediaService()
{

}

const std::vector<Media>& MediaService::GetMediaList()
{
	return _mediaList;
}
