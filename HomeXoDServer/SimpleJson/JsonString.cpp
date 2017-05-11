#include "JsonString.h"

JsonString::JsonString()
{

}

JsonString::JsonString(const std::string &str)
	: _str(str)
{

}

JsonString::JsonString(const char *str)
	: _str(str)
{

}

JsonString::operator const std::string&() const
{
	return _str;
}

std::string JsonString::ToString() const
{
	return "\"" + _str + "\"";
}

bool JsonString::operator <(const JsonString &rhs) const
{
	return _str < rhs._str;
}
