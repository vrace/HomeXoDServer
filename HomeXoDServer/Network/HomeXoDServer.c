#include <stdlib.h>
#include "HomeXoDServer.h"

struct HomeXoDServer
{
	MEDIA_DELEGATE *mediaDelegate;
	APPLICATION_DELEGATE *applicationDelegate;
};

HOME_XOD_SERVER* ServerAlloc(void)
{
	return malloc(sizeof(HOME_XOD_SERVER));
}

HOME_XOD_SERVER* ServerInit(HOME_XOD_SERVER *server)
{
	server->mediaDelegate = NULL;
	server->applicationDelegate = NULL;

	return server;
}

void ServerRelease(HOME_XOD_SERVER *server)
{
	free(server);
}

void ServerSetMediaDelegate(HOME_XOD_SERVER *server, MEDIA_DELEGATE *mediaDelegate)
{
	server->mediaDelegate = mediaDelegate;
}

void ServerSetApplicationDelegate(HOME_XOD_SERVER *server, APPLICATION_DELEGATE *applicationDelegate)
{
	server->applicationDelegate = applicationDelegate;
}

void ServerRun(HOME_XOD_SERVER *server)
{

}
