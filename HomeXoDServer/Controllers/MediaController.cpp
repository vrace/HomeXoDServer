#include "../Common.h"
#include "MediaController.h"

MediaController::MediaController()
	: _mediaListInitialized(false)
{

}

const MediaArray& MediaController::MediaRetrieveList(bool refresh)
{
	if (!_mediaListInitialized || refresh)
		RefreshMediaList();

	return _mediaList;
}

void MediaController::MediaStop()
{

}

bool MediaController::MediaPlay(int mediaId)
{
	return false;
}

void MediaController::RefreshMediaList()
{
	// TODO: Refresh the media list by search for media files

	_mediaListInitialized = true;
}
