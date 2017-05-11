#include "MediaController.h"
#include "../Translator/MediaTranslator.h"

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

	JsonObject *dataJson = MediaTranslator::Translate(mediaList);
	std::string payload = dataJson->ToString();
	delete dataJson;

	return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, payload);
}
