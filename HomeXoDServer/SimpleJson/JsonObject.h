#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "JsonValue.h"
#include <map>

class JsonObject
	: public JsonValue
	, public std::map<std::string, JsonValue*>
{
public:
	JsonObject();
	virtual ~JsonObject();
	virtual std::string ToString();

private:
	JsonObject(const JsonObject&);
	JsonObject& operator =(const JsonObject&);
};

#endif
