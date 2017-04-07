#include <stdlib.h>
#include <string.h>
#include "Media.h"

MEDIA* MediaInit(MEDIA *media, const char *mediaName)
{
	media->id = 0;
	media->next = NULL;
	media->name = strdup(mediaName);

	return media;
}

void MediaRelease(MEDIA *media)
{
	free(media->name);
	media->name = NULL;
}
