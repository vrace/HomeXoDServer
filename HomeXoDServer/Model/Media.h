#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media
{
public:
	Media();

	void SetName(const std::string &name);
	const std::string& GetName() const;

private:
	std::string _name;
};

#endif
