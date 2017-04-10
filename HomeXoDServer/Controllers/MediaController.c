#include <stdlib.h>
#include "MediaController.h"
#include "../Delegates/MediaDelegate.h"
#include "../Models/MediaList.h"

struct MediaController
{
	MEDIA_DELEGATE base;
	MEDIA_LIST *mediaList;
};

static MEDIA_LIST* RefreshMediaList(MEDIA_CONTROLLER *controller)
{
	MEDIA_LIST **mediaList = &controller->mediaList;

	if (!*mediaList)
		*mediaList = MediaListInit(MediaListAlloc());

	MediaListClear(*mediaList);

	// Have some fun
	MediaListConcat(*mediaList, MediaInit(MediaAlloc(), "Something"));
	MediaListConcat(*mediaList, MediaInit(MediaAlloc(), "For"));
	MediaListConcat(*mediaList, MediaInit(MediaAlloc(), "Nothing"));

	return *mediaList;
}

MEDIA_CONTROLLER* MediaControllerAlloc(void)
{
	return malloc(sizeof(MEDIA_CONTROLLER));
}

MEDIA_CONTROLLER* MediaControllerInit(MEDIA_CONTROLLER *controller)
{
	controller->base.retrieveList = (MEDIA_RETRIEVE_LIST)RefreshMediaList;
	controller->base.stop = NULL;
	controller->base.play = NULL;

	controller->mediaList = NULL;

	return controller;
}

void MediaControllerRelease(MEDIA_CONTROLLER *controller)
{
	MediaListRelease(controller->mediaList);
	free(controller);
}
