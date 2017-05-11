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

std::string JsonObject::ToString() const
{
	if (empty())
		return "{}";

	std::stringstream ss;
	ss << "{";

	const_iterator it = begin();
	if (it != end())
	{
		ss << it->first.ToString() << ":" << it->second->ToString();

		for (++it; it != end(); ++it)
			ss << it->first.ToString() << ":" << it->second->ToString();
	}

	ss << "}";

	return ss.str();
}
