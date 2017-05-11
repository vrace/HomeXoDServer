#ifndef JSON_STRING_H
#define JSON_STRING_H

#include "JsonValue.h"

class JsonString : public JsonValue
{
public:
	JsonString();
	JsonString(const std::string &str);
	JsonString(const char *str);

	operator const std::string&() const;
	virtual std::string ToString() const;

	bool operator < (const JsonString &rhs) const;

private:
	std::string _str;
};

#endif
