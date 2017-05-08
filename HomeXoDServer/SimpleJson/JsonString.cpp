#include "JsonString.h"

JsonString::JsonString()
{

}

JsonString::JsonString(const std::string &str)
	: _str(str)
{

}

JsonString::operator const std::string&() const
{
	return _str;
}

std::string JsonString::ToString()
{
	return "\"" + _str + "\"";
}
