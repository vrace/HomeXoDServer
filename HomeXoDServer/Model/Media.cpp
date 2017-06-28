#include "Media.h"
#include "../sha256/sha256.h"

Media::Media()
{

}

void Media::SetName(const std::string &name)
{
	_name = name;
	_id = SHA256Hex(name);
}
