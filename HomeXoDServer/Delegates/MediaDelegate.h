#ifndef MEDIA_DELEGATE_H
#define MEDIA_DELEGATE_H

#include "../Models/MediaList.h"

typedef struct MediaDelegate MEDIA_DELEGATE;

typedef MEDIA_LIST* (*MEDIA_RETRIEVE_LIST)(MEDIA_DELEGATE*);
typedef void (*MEDIA_STOP)(MEDIA_DELEGATE*);
typedef void (*MEDIA_PLAY)(MEDIA_DELEGATE*, int);

struct MediaDelegate
{
	MEDIA_RETRIEVE_LIST retrieveList;
	MEDIA_STOP stop;
	MEDIA_PLAY play;
};

#endif
