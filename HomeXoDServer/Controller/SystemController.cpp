#include "SystemController.h"
#include "../Base/HttpResponseEntity.h"
#include "../SimpleJson/JsonObject.h"
#include "../SimpleJson/JsonString.h"

HttpResponse* SystemController::Dispatch(const HttpRequest &request)
{
	RequestURL url = request.GetURL("/system");

	if (url)
	{
		if (url.GetComponentSize() == 1 && url[0] == "version")
			return GetVersion();

		if (url.GetComponentSize() == 1 && url[0] == "shutdown")
			return Shutdown();
	}

	return NULL;
}

HttpResponse* SystemController::GetVersion()
{
	const std::string &version = _service.GetVersion();

	JsonObject dataJson;
	dataJson.Put("version", version);

	return new HttpResponseEntity<JsonObject>(HTTP_STATUS_OK, dataJson);
}

HttpResponse* SystemController::Shutdown()
{
	_service.Shutdown();
	return new HttpResponseEntity<JsonObject>(HTTP_STATUS_OK, JsonObject());
}
