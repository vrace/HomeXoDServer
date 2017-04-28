#ifndef VERSION_CONTROLLER_H
#define VERSION_CONTROLLER_H

#include "../Base/RestController.h"
#include "../Service/VersionService.h"

class VersionController : public RestController
{
public:
	HttpResponse* Dispatch(const HttpRequest &request);

protected:
	HttpResponse* GetVersion();

private:
	VersionService _service;
};

#endif
