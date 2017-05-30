#include "BasicAuthCredential.h"

BasicAuthCredential::BasicAuthCredential()
{

}

BasicAuthCredential::BasicAuthCredential(const std::string &user, const std::string &password)
	: std::pair<std::string, std::string>(user, password)
{

}

const std::string& BasicAuthCredential::GetName() const
{
	return this->first;
}

const std::string& BasicAuthCredential::GetPassword() const
{
	return this->second;
}

BasicAuthCredential::operator bool() const
{
	return !GetName().empty();
}
