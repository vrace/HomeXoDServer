#ifndef MEDIA_CONTROLLER_H
#define MEDIA_CONTROLLER_H

#include "../Base/RestController.h"
#include "../Service/MediaService.h"

class MediaController : public RestController
{
public:
	HttpResponse* Dispatch(const HttpRequest &request);

protected:
	HttpResponse* GetMediaList();

private:
	MediaService _service;
};

#endif
