#ifndef AUTHENTICATION_MANAGER_H
#define AUTHENTICATION_MANAGER_H

#include "HttpRequest.h"
#include "HttpResponse.h"

class AuthenticationManager
{
public:
	AuthenticationManager();
	virtual ~AuthenticationManager();

	virtual bool Authenticate(const HttpRequest &request) = 0;
	virtual HttpResponse* UnauthorizedResponse(const HttpRequest &request) = 0;
};

#endif
