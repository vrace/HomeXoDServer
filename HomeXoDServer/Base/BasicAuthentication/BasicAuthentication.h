#ifndef BASIC_AUTHENTICATION_H
#define BASIC_AUTHENTICATION_H

#include "../AuthenticationManager.h"
#include "BasicAuthCredential.h"
#include "BasicAuthRule.h"
#include <map>
#include <vector>

class BasicAuthentication : public AuthenticationManager
{
public:
	BasicAuthentication();
	~BasicAuthentication();

	bool Authenticate(const HttpRequest &request);
	HttpResponse* UnauthorizedResponse(const HttpRequest &request);

	void AddUser(const BasicAuthCredential &user, const std::string &roles);
	void AddRule(BasicAuthRule *rule);

private:
	BasicAuthCredential ExtractAuth(const HttpRequest &request);

private:
	std::map<BasicAuthCredential, std::string> _users;
	std::vector<BasicAuthRule*> _rules;
};

#endif
