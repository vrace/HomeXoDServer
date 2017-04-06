#include "../Common.h"
#include "Media.h"

Media::Media()
	: _id(0)
{

}

int Media::ID() const
{
	return _id;
}

const std::wstring& Media::Name() const
{
	return _name;
}

void Media::SetName(const std::wstring &name)
{
	_name = name;
	// TODO: recalculate the id
}
