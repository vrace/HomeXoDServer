#include "MediaController.h"

HttpResponse* MediaController::Dispatch(const HttpRequest &request)
{
	RequestURL url = request.GetURL("/media");

	if (url)
	{
		if (url.GetComponentSize() == 1 && url[0] == "list")
			return GetMediaList();
	}

	return NULL;
}

HttpResponse* MediaController::GetMediaList()
{
	const std::vector<Media> &mediaList = _service.GetMediaList();

	HttpHeader header;
	SetContentType(header, "application/media-list.v1.json");

	return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, "");
}

