#include <stdlib.h>
#include "MediaList.h"

struct MediaList
{
	MEDIA *first;
};

MEDIA_LIST* MediaListAlloc(void)
{
	return malloc(sizeof(MEDIA_LIST));
}

MEDIA_LIST* MediaListInit(MEDIA_LIST *mediaList)
{
	mediaList->first = NULL;
	return mediaList;
}

void MediaListRelease(MEDIA_LIST *mediaList)
{
	if (!mediaList)
		return;

	MediaListClear(mediaList);
	free(mediaList);
}

void MediaListClear(MEDIA_LIST *mediaList)
{
	MEDIA *current;
	MEDIA *next;

	current = mediaList->first;

	while (current)
	{
		next = current->next;
		MediaRelease(current);
		current = next;
	}

	mediaList->first = NULL;
}

void MediaListConcat(MEDIA_LIST *mediaList, MEDIA *media)
{
	MEDIA **cur;

	for (cur = &mediaList->first; *cur != NULL; cur = &(*cur)->next)
		;

	*cur = media;
}

int MediaListCount(MEDIA_LIST *mediaList)
{
	int count = 0;
	MEDIA *cur = mediaList->first;

	while (cur)
	{
		count++;
		cur = cur->next;
	}

	return count;
}

MEDIA* MediaListGetFirst(MEDIA_LIST *mediaList)
{
	return mediaList->first;
}
