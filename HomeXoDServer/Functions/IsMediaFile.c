#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *MEDIA_TYPES[] =
{
	"",
	".mkv",
	".avi",
	".mp4",
};

int IsMediaFile(const char *pathName)
{
	int i;
	const char *extensionBegin;

	extensionBegin = strrchr(pathName, '.');

	if (!extensionBegin)
		return 0;

	for (i = 1; i < sizeof(MEDIA_TYPES) / sizeof(MEDIA_TYPES[0]); i++)
	{
		if (_strcmpi(extensionBegin, MEDIA_TYPES[i]) == 0)
			return i;
	}

	return 0;
}
