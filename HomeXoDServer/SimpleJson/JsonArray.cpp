#include "JsonArray.h"
#include <sstream>

JsonArray::JsonArray()
{

}

JsonArray::~JsonArray()
{
	for (iterator it = begin(); it != end(); ++it)
		delete *it;
}

std::string JsonArray::ToString() const
{
	std::stringstream ss;

	ss << "[";

	const_iterator it = begin();
	if (it != end())
	{
		ss << (*it)->ToString();

		for (++it; it != end(); ++it)
			ss << "," << (*it)->ToString();
	}

	ss << "]";

	return ss.str();
}
