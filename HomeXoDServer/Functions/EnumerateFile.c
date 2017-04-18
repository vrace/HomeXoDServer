#include "EnumerateFile.h"
#include <Windows.h>
#include <stdlib.h>

static const char ALL_FILES[] = "\\*";

static void EnumFileImpl(const char *root, const char *relative, ENUMERATE_FILE_ARGS *args)
{
	HANDLE hf;
	WIN32_FIND_DATA wfd;
	char *term;
	char *found;

	term = malloc(strlen(root) + strlen(relative) + strlen(ALL_FILES) + 100);
	strcpy(term, root);
	strcat(term, "\\");
	strcat(term, relative);
	strcat(term, ALL_FILES);

	found = malloc(strlen(relative) + 100 + MAX_PATH);

	hf = FindFirstFile(term, &wfd);
	while (hf != INVALID_HANDLE_VALUE)
	{
		if (strchr(wfd.cFileName, '.') != wfd.cFileName)
		{
			if ((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				strcpy(found, relative);
				strcat(found, wfd.cFileName);
				strcat(found, "\\");

				EnumFileImpl(root, found, args);
			}
			else
			{
				strcpy(found, relative);
				strcat(found, wfd.cFileName);

				args->processPathName(args, found);
			}
		}

		if (!FindNextFile(hf, &wfd))
		{
			FindClose(hf);
			hf = INVALID_HANDLE_VALUE;
		}
	}

	free(found);
	free(term);
}

void EnumerateFile(const char *path, ENUMERATE_FILE_ARGS *args)
{
	EnumFileImpl(path, "", args);
}
