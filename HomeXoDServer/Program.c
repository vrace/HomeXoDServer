#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Network/HomeXoDServer.h"
#include "Controllers/MediaController.h"

void ApplicationRun(void);

int main(void)
{
	setlocale(LC_ALL, "zh-CN");
	ApplicationRun();
	return 0;
}

void ApplicationRun(void)
{
	HOME_XOD_SERVER *server;
	MEDIA_CONTROLLER *media;

	server = ServerInit(ServerAlloc());
	media = MediaControllerInit(MediaControllerAlloc());
	
	ServerSetMediaDelegate(server, (MEDIA_DELEGATE*)media);
	ServerRun(server);

	MediaControllerRelease(media);
	ServerRelease(server);
}
