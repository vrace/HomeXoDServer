#include "MediaController.h"
#include <sstream>
#include <iostream>

std::ostream& operator <<(std::ostream &s, const Media &media)
{
	s << media.GetName();
	return s;
}

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
	SetContentType(header, "text/plain; charset=utf-8");

	std::stringstream ss;
	std::copy(mediaList.begin(), mediaList.end(), std::ostream_iterator<Media>(ss, "\r\n"));

	return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, ss.str());
}
