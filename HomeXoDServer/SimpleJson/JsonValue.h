#ifndef JSON_VALUE_H
#define JSON_VALUE_H

#include <string>

class JsonValue
{
public:
	JsonValue();
	virtual ~JsonValue();

	virtual std::string ToString() const = 0;
};

#endif
