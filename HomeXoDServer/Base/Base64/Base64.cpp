#include "Base64.h"
#include "Impl/base64.h"

std::vector<char> Base64::Decode(const std::string &encoded)
{
	std::vector<char> buf;
	buf.resize(Base64decode_len(encoded.c_str()) + 1);

	int len = Base64decode(&buf[0], encoded.c_str());
	buf.resize(len);

	return buf;
}
