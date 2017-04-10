#ifndef MEDIA_CONTROLLER_H
#define MEDIA_CONTROLLER_H

typedef struct MediaController MEDIA_CONTROLLER;

MEDIA_CONTROLLER* MediaControllerAlloc(void);
MEDIA_CONTROLLER* MediaControllerInit(MEDIA_CONTROLLER *controller);
void MediaControllerRelease(MEDIA_CONTROLLER *controller);

#endif
