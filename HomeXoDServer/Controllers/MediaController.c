#include <stdlib.h>
#include "MediaController.h"

MEDIA_CONTROLLER* MediaControllerAlloc(void)
{
	return malloc(sizeof(MEDIA_CONTROLLER));
}

MEDIA_CONTROLLER* MediaControllerInit(MEDIA_CONTROLLER *controller)
{
	controller->base.retrieveList = NULL;
	controller->base.stop = NULL;
	controller->base.play = NULL;
	
	controller->firstMedia = NULL;

	return controller;
}

void MediaControllerRelease(MEDIA_CONTROLLER *controller)
{
	// TOOD: release media list
	free(controller);
}
