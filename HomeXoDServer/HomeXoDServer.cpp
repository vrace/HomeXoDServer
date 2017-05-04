#include "HomeXoDServer.h"
#include "Controller/VersionController.h"
#include "Controller/MediaController.h"

bool HomeXoDServer::Init()
{
	AddController(new VersionController());
	AddController(new MediaController());
	return SimpleWinSockServer::Init();
}
