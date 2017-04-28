#include "VersionService.h"

const std::string& VersionService::GetVersion() const
{
	static const std::string VERSION = "Home XOD Server v0.1";
	return VERSION;
}
