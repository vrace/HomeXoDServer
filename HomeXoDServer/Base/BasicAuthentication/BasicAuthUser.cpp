#include "BasicAuthUser.h"
#include <algorithm>
#include <sstream>

BasicAuthUser::BasicAuthUser(const std::pair<BasicAuthCredential, std::string> &auth)
	: BasicAuthUser(auth.first, auth.second)
{

}

BasicAuthUser::BasicAuthUser(const BasicAuthCredential &credential, const std::string &roles)
	: _credential(credential)
{
	InitRoles(roles);
}

const BasicAuthCredential& BasicAuthUser::GetCredential() const
{
	return _credential;
}

bool BasicAuthUser::HasRole(const std::string &role) const
{
	return std::find(_roles.begin(), _roles.end(), role) != _roles.end();
}

void BasicAuthUser::InitRoles(const std::string &roles)
{
	std::stringstream ss(roles);
	std::string role;

	while (std::getline(ss, role, '|'))
		_roles.push_back(role);
}
