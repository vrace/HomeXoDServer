#ifndef MEDIA_H
#define MEDIA_H

#include "../Common.h"

class Media
{
public:
	Media();

	int ID() const;
	const std::wstring& Name() const;

	void SetName(const std::wstring &name);
	
private:
	std::wstring _name;
	int _id;
};

typedef std::vector<Media> MediaArray;

#endif
