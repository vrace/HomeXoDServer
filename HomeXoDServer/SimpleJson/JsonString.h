#ifndef JSON_STRING_H
#define JSON_STRING_H

#include "JsonValue.h"

class JsonString : public JsonValue
{
public:
	JsonString();
	JsonString(const std::string &str);

	operator const std::string&() const;
	virtual std::string ToString();

private:
	std::string _str;
};

#endif
