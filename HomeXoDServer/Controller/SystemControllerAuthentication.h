#ifndef SYSTEM_CONTROLLER_AUTHENTICATION_H
#define SYSTEM_CONTROLLER_AUTHENTICATION_H

#include "../Base/BasicAuthentication/BasicAuthRule.h"

class SystemControllerAuthentication : public BasicAuthRule
{
public:
	virtual bool Matches(const HttpRequest &request);
	virtual bool Authenticate(const HttpRequest &request, const BasicAuthUser &user);
};

#endif
