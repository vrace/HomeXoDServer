#ifndef BASIC_AUTH_USER_H
#define BASIC_AUTH_USER_H

#include "BasicAuthCredential.h"
#include <vector>
#include <utility>

class BasicAuthUser
{
public:
	BasicAuthUser(const std::pair<BasicAuthCredential, std::string> &auth);
	BasicAuthUser(const BasicAuthCredential &credential, const std::string &roles);

	const BasicAuthCredential& GetCredential() const;
	bool HasRole(const std::string &role) const;

private:
	void InitRoles(const std::string &roles);

private:
	BasicAuthCredential _credential;
	std::vector<std::string> _roles;
};

#endif
