#include "MediaTranslator.h"
#include "../SimpleJson/JsonArray.h"
#include "../SimpleJson/JsonString.h"

JsonObject* MediaTranslator::Translate(const Media &media)
{
	JsonObject *data = new JsonObject();
	JsonObject &dataJson = *data;

	dataJson["id"] = new JsonString(media.GetID());
	dataJson["name"] = new JsonString(media.GetName());

	return data;
}

JsonObject* MediaTranslator::Translate(const std::vector<Media> &mediaList)
{
	JsonObject *data = new JsonObject();
	JsonObject &dataJson = *data;

	JsonArray *arr = new JsonArray();

	for (std::vector<Media>::const_iterator it = mediaList.begin(); it != mediaList.end(); ++it)
		arr->push_back(Translate(*it));

	dataJson["media_list"] = arr;

	return data;
}
