#ifndef SYSTEM_SERVICE_H
#define SYSTEM_SERVICE_H

#include <string>

class SystemService
{
public:
	const std::string& GetVersion() const;
	void Shutdown();
};

#endif
