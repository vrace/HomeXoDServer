#ifndef ENUMERATE_FILE_H
#define ENUMERATE_FILE_H

typedef struct EnumerateFileArgs ENUMERATE_FILE_ARGS;
typedef void (*ENUM_FILE_PROC)(ENUMERATE_FILE_ARGS *args, const char *pathName);

struct EnumerateFileArgs
{
	ENUM_FILE_PROC processPathName;
};

void EnumerateFile(const char *path, ENUMERATE_FILE_ARGS *args);

#endif
