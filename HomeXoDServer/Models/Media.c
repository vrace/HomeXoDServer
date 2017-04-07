#include <stdlib.h>
#include <string.h>
#include "Media.h"

MEDIA* MediaAlloc(void)
{
	return malloc(sizeof(MEDIA));
}

MEDIA* MediaInit(MEDIA *media, const char *mediaName)
{
	// TODO: Generate unique ID
	media->id = 0;
	media->next = NULL;
	media->name = strdup(mediaName);

	return media;
}

void MediaRelease(MEDIA *media)
{
	free(media->name);
	free(media);
}
