#include "HomeXoDServer.h"
#include "Controller/SystemController.h"
#include "Controller/MediaController.h"

bool HomeXoDServer::Init()
{
	AddController(new SystemController());
	AddController(new MediaController());
	return SimpleWinSockServer::Init();
}
