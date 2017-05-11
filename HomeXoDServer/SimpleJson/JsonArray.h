#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include "JsonValue.h"
#include <vector>

class JsonArray
	: public JsonValue
	, public std::vector<JsonValue*>
{
public:
	JsonArray();
	virtual ~JsonArray();
	virtual std::string ToString() const;
};

#endif
