#include "SystemControllerAuthentication.h"

bool SystemControllerAuthentication::Matches(const HttpRequest &request)
{
	RequestURL url = request.GetURL("/system");
	return url && url.GetComponentSize() == 1 && url[0] == "shutdown";
}

bool SystemControllerAuthentication::Authenticate(const HttpRequest &request, const BasicAuthUser &user)
{
	return user.HasRole("ADMIN");
}
