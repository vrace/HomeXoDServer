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
	std::string dup = _str;
	std::string::size_type pos = 0;

	for (pos = dup.find('\\'); pos != std::string::npos; pos = dup.find('\\', pos))
	{
		dup.replace(pos, 1, "\\\\");
		pos += 2;
	}

	for (pos = dup.find('"'); pos != std::string::npos; pos = dup.find('"', pos))
	{
		dup.replace(pos, 1, "\\\"");
		pos += 2;
	}

	return "\"" + dup + "\"";
}

bool JsonString::operator <(const JsonString &rhs) const
{
	return _str < rhs._str;
}
