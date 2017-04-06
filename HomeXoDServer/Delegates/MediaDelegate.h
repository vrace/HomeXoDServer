#ifndef MEDIA_DELEGATE_H
#define MEDIA_DELEGATE_H

#include "../Common.h"
#include "../Models/Media.h"

class MediaDelegate
{
public:
	virtual const MediaArray& MediaRetrieveList(bool refresh) = 0;
	virtual void MediaStop() = 0;
	virtual bool MediaPlay(int mediaId) = 0;
};

#endif
