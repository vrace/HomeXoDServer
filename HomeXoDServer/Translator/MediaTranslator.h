#ifndef MEDIA_TRANSLATOR_H
#define MEDIA_TRANSLATOR_H

#include "../SimpleJson/JsonObject.h"
#include "../Model/Media.h"
#include <vector>

class MediaTranslator
{
public:
	static JsonObject* Translate(const Media &media);
	static JsonObject* Translate(const std::vector<Media> &mediaList);
};

#endif
