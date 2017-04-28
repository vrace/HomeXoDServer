#ifndef VERSION_SERVICE_H
#define VERSION_SERVICE_H

#include "VersionService.h"
#include <string>

class VersionService
{
public:
	const std::string& GetVersion() const;
};

#endif
