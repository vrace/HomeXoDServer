#include "SystemService.h"
#include "../HomeXoDServer.h"

extern HomeXoDServer theServer;

const std::string& SystemService::GetVersion() const
{
	static const std::string VERSION = "Home XOD Server v0.1";
	return VERSION;
}

void SystemService::Shutdown()
{
	theServer.PrepareShutdown();
}
