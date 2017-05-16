#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include "../Base/RestController.h"
#include "../Service/SystemService.h"

class SystemController : public RestController
{
public:
	HttpResponse* Dispatch(const HttpRequest &request);

protected:
	HttpResponse* GetVersion();
	HttpResponse* Shutdown();

private:
	SystemService _service;
};

#endif
