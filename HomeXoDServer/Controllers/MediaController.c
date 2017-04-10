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

static void EnumMediaFiles(MEDIA_CONTROLLER *controller)
{
	HANDLE hf;
	WIN32_FIND_DATA wfd;
	char *term;
	const char *all = "\\*";

	term = malloc(strlen(GetMediaPath(controller)) + strlen(all) + 1);
	strcpy(term, GetMediaPath(controller));
	strcat(term, all);

	hf = FindFirstFile(term, &wfd);
	while (hf != INVALID_HANDLE_VALUE)
	{
		// TODO: search into directory
		// TODO: filter media files

		MEDIA *media = MediaInit(MediaAlloc(), wfd.cFileName);
		MediaListConcat(GetMediaList(controller), media);

		if (!FindNextFile(hf, &wfd))
		{
			FindClose(hf);
			hf = INVALID_HANDLE_VALUE;
		}
	}

	free(term);
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
