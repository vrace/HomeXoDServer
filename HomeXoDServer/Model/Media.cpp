#include "Media.h"

Media::Media()
{

}

void Media::SetName(const std::string &name)
{
	_name = name;
}

const std::string& Media::GetName() const
{
	return _name;
}
