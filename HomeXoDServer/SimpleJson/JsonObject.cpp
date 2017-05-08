#include "JsonObject.h"
#include <sstream>

JsonObject::JsonObject()
{

}

JsonObject::~JsonObject()
{
	for (iterator it = begin(); it != end(); ++it)
		delete it->second;
}

std::string JsonObject::ToString()
{
	if (empty())
		return "{}";

	std::stringstream ss;
	ss << "{";

	iterator it = begin();
	if (it != end())
	{
		ss << "\"" << it->first << "\":" << it->second->ToString();

		for (++it; it != end(); ++it)
			ss << ",\"" << it->first << "\":" << it->second->ToString();
	}

	ss << "}";

	return ss.str();
}
