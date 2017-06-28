#ifndef MEDIA_H
#define MEDIA_H

#include <string>

class Media
{
public:
	Media();

	void SetName(const std::string &name);

	const std::string& GetName() const { return _name; }
	const std::string& GetID() const { return _id; }

private:
	std::string _name;
	std::string _id;
};

#endif
