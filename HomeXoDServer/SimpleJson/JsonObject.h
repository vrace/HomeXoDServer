#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "JsonValue.h"
#include "JsonString.h"
#include <map>

class JsonObject
	: public JsonValue
	, public std::map<JsonString, JsonValue*>
{
public:
	JsonObject();
	virtual ~JsonObject();
	virtual std::string ToString() const;

private:
	JsonObject(const JsonObject&);
	JsonObject& operator =(const JsonObject&);
};

#endif
