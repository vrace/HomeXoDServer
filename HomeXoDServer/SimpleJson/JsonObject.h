#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "JsonValue.h"
#include <map>
#include <string>

class JsonObject : public JsonValue
{
public:
	typedef std::map<std::string, JsonValue*> MapType;

public:
	JsonObject();
	virtual ~JsonObject();

	virtual std::string ToString();

	bool ContainsKey(const std::string &key) const;
	JsonValue* operator [](const std::string &key);
	void Put(const std::string &key, JsonValue *value);

private:
	MapType _elements;
};

#endif
