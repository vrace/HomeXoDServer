#include <Windows.h>
#include <ShlObj.h>
#include <stdlib.h>
#include "MediaController.h"
#include "../Delegates/MediaDelegate.h"
#include "../Models/MediaList.h"

struct MediaController
{
	MEDIA_DELEGATE base;
	MEDIA_LIST *mediaList;
	char *mediaPath;
};

static const char* GetMediaPath(MEDIA_CONTROLLER *controller)
{
	PWSTR downloadPath;

	if (controller->mediaPath)
		return controller->mediaPath;

	if (SHGetKnownFolderPath(&FOLDERID_Downloads, KF_FLAG_DEFAULT, NULL, &downloadPath) != S_OK)
	{
		controller->mediaPath = _strdup(".\\");
	}
	else
	{
		int len;
		char *buffer;

		len = MB_CUR_MAX * wcslen(downloadPath);
		buffer = malloc(len + 1);

		wcstombs(buffer, downloadPath, len);
		buffer[len] = '\0';

		CoTaskMemFree(downloadPath);
		controller->mediaPath = buffer;
	}

	return controller->mediaPath;
}

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
	MediaListConcat(*mediaList, MediaInit(MediaAlloc(), GetMediaPath(controller)));

	return *mediaList;
}

static void StopMedia(MEDIA_CONTROLLER *controller)
{
	// TODO: Kill media player process?
}

static void StartMedia(MEDIA_CONTROLLER *controller)
{
	// TODO: Start media by launch media player?
}

MEDIA_CONTROLLER* MediaControllerAlloc(void)
{
	return malloc(sizeof(MEDIA_CONTROLLER));
}

MEDIA_CONTROLLER* MediaControllerInit(MEDIA_CONTROLLER *controller)
{
	controller->base.retrieveList = (MEDIA_RETRIEVE_LIST)RefreshMediaList;
	controller->base.stop = (MEDIA_STOP)StopMedia;
	controller->base.play = (MEDIA_PLAY)StartMedia;

	controller->mediaList = NULL;
	controller->mediaPath = NULL;

	return controller;
}

void MediaControllerRelease(MEDIA_CONTROLLER *controller)
{
	if (!controller)
		return;

	MediaListRelease(controller->mediaList);
	free(controller->mediaPath);
	free(controller);
}
