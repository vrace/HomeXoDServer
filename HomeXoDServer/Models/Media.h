#ifndef MEDIA_H
#define MEDIA_H

typedef struct Media
{
	int id;
	char *name;
	struct Media *next;
} MEDIA;

MEDIA* MediaInit(MEDIA *media, const char *mediaName);
void MediaRelease(MEDIA *media);

#endif
