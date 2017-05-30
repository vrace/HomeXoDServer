#ifndef BASE_64_H
#define BASE_64_H

#include <string>
#include <vector>

class Base64
{
public:
	static std::vector<char> Decode(const std::string &encoded);
};

#endif
