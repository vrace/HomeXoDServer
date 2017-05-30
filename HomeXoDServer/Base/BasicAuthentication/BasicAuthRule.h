#ifndef BASIC_AUTH_RULE_H
#define BASIC_AUTH_RULE_H

#include "../HttpRequest.h"
#include "BasicAuthUser.h"

class BasicAuthRule
{
public:
	BasicAuthRule();
	virtual ~BasicAuthRule();

	virtual bool Matches(const HttpRequest &request) = 0;
	virtual bool Authenticate(const HttpRequest &request, const BasicAuthUser &user) = 0;
};

#endif
