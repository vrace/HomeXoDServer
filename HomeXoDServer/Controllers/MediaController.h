#ifndef MEDIA_CONTROLLER_H
#define MEDIA_CONTROLLER_H

#include "../Common.h"
#include "../Delegates/MediaDelegate.h"

class MediaController : public MediaDelegate
{
public:
	MediaController();

	virtual const MediaArray& MediaRetrieveList(bool refresh);
	virtual void MediaStop();
	virtual bool MediaPlay(int mediaId);

private:
	void RefreshMediaList();

private:
	bool _mediaListInitialized;
	std::vector<Media> _mediaList;
};

#endif
