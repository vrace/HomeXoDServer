#include "MediaController.h"
#include "../Base/HttpResponseEntity.h"
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
	JsonObject *dataJson = MediaTranslator::Translate(mediaList);
	return new HttpResponseEntity<JsonObject>(HTTP_STATUS_OK, dataJson);
}
