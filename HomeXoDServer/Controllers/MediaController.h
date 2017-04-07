#ifndef MEDIA_CONTROLLER_H
#define MEDIA_CONTROLLER_H

#include "../Delegates/MediaDelegate.h"
#include "../Models/Media.h"

typedef struct MediaController
{
	MEDIA_DELEGATE base;
	MEDIA *firstMedia;
} MEDIA_CONTROLLER;

MEDIA_CONTROLLER* MediaControllerAlloc(void);
MEDIA_CONTROLLER* MediaControllerInit(MEDIA_CONTROLLER *controller);
void MediaControllerRelease(MEDIA_CONTROLLER *controller);

#endif
