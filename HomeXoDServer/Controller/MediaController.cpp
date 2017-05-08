#include "MediaController.h"
#include "../SimpleJson/JsonObject.h"
#include "../SimpleJson/JsonArray.h"
#include "../SimpleJson/JsonString.h"

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

	JsonObject dataJson;
	JsonArray *arr = new JsonArray();
	for (std::vector<Media>::const_iterator it = mediaList.begin(); it != mediaList.end(); ++it)
	{
		JsonString *str = new JsonString(it->GetName());
		arr->push_back(str);
	}
	dataJson["media_list"] = arr;

	return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, dataJson.ToString());
}
