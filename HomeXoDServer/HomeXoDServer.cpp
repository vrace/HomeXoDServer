#include "HomeXoDServer.h"
#include "Controller/VersionController.h"

bool HomeXoDServer::Init()
{
	AddController(new VersionController());
	return SimpleWinSockServer::Init();
}
