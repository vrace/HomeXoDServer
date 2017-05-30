#ifndef BASIC_AUTH_CREDENTIAL_H
#define BASIC_AUTH_CREDENTIAL_H

#include <string>
#include <utility>

class BasicAuthCredential : public std::pair<std::string, std::string>
{
public:
	BasicAuthCredential();
	BasicAuthCredential(const std::string &user, const std::string &password);

	const std::string& GetName() const;
	const std::string& GetPassword() const;

	operator bool() const;
};

#endif
