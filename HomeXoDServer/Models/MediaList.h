#ifndef MEDIA_LIST_H
#define MEDIA_LIST_H

#include "Media.h"

typedef struct MediaList MEDIA_LIST;

MEDIA_LIST* MediaListAlloc(void);
MEDIA_LIST* MediaListInit(MEDIA_LIST *mediaList);
void MediaListRelease(MEDIA_LIST *mediaList);

void MediaListConcat(MEDIA_LIST *mediaList, MEDIA *media);
void MediaListClear(MEDIA_LIST *mediaList);

int MediaListCount(MEDIA_LIST *mediaList);
MEDIA* MediaListGetFirst(MEDIA_LIST *mediaList);

#endif
