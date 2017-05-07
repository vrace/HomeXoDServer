#include "JsonObject.h"
#include <sstream>

JsonObject::JsonObject()
{

}

JsonObject::~JsonObject()
{
	for (MapType::iterator it = _elements.begin(); it != _elements.end(); ++it)
		delete it->second;
}

bool JsonObject::ContainsKey(const std::string &key) const
{
	return _elements.find(key) != _elements.end();
}

JsonValue* JsonObject::operator [](const std::string &key)
{
	MapType::iterator it = _elements.find(key);
	
	if (it != _elements.end())
		return it->second;

	return NULL;
}

void JsonObject::Put(const std::string &key, JsonValue *value)
{
	_elements[key] = value;
}

std::string JsonObject::ToString()
{
	if (_elements.empty())
		return "{}";

	std::stringstream ss;
	ss << "{";

	MapType::iterator it = _elements.begin();
	ss << "\"" << it->first << "\":" << it->second->ToString();

	for (; it != _elements.end(); ++it)
		ss << ",\"" << it->first << "\":" << it->second->ToString();

	ss << "}";

	return ss.str();
}
