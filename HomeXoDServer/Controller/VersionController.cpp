#include "VersionController.h"

HttpResponse* VersionController::Dispatch(const HttpRequest &request)
{
	RequestURL url = request.GetURL("/version");

	if (url)
	{
		if (url.GetComponentSize() == 0)
			return GetVersion();
	}

	return NULL;
}

HttpResponse* VersionController::GetVersion()
{
	HttpHeader header;
	header["Content-Type"] = "text/plain";

	const std::string &version = _service.GetVersion();

	return new HttpResponse(HttpStatus(HTTP_STATUS_OK), header, version);
}
