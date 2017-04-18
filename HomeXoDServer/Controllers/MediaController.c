#include <Windows.h>
#include <ShlObj.h>
#include <stdlib.h>
#include "MediaController.h"
#include "../Delegates/MediaDelegate.h"
#include "../Models/MediaList.h"
#include "../Functions/EnumerateFile.h"

struct MediaController
{
	MEDIA_DELEGATE base;
	MEDIA_LIST *mediaList;
	char *mediaPath;
};

typedef struct MediaControllerEnumFilesArgs
{
	ENUMERATE_FILE_ARGS base;
	MEDIA_CONTROLLER *controller;
} MEDIA_CONTROLLER_ENUM_FILE_ARGS;

static MEDIA_LIST* GetMediaList(MEDIA_CONTROLLER *controller)
{
	if (!controller->mediaList)
		controller->mediaList = MediaListInit(MediaListAlloc());

	return controller->mediaList;
}

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

static void EnumFileProc(MEDIA_CONTROLLER_ENUM_FILE_ARGS *args, const char *pathName)
{
	MEDIA *media = MediaInit(MediaAlloc(), pathName);
	MediaListConcat(GetMediaList(args->controller), media);
}

static void EnumMediaFiles(MEDIA_CONTROLLER *controller)
{
	MEDIA_CONTROLLER_ENUM_FILE_ARGS args;
	
	args.base.processPathName = (ENUM_FILE_PROC)EnumFileProc;
	args.controller = controller;

	MediaListClear(GetMediaList(controller));
	EnumerateFile(GetMediaPath(controller), (ENUMERATE_FILE_ARGS*)&args);
}

static MEDIA_LIST* RefreshMediaList(MEDIA_CONTROLLER *controller)
{
	MEDIA_LIST *mediaList = GetMediaList(controller);

	MediaListClear(mediaList);
	EnumMediaFiles(controller);

	return mediaList;
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
