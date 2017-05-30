#include "BasicAuthentication.h"
#include "../Base64/Base64.h"

BasicAuthentication::BasicAuthentication()
{

}

BasicAuthentication::~BasicAuthentication()
{
	for (std::vector<BasicAuthRule*>::iterator it = _rules.begin(); it != _rules.end(); ++it)
		delete *it;
}

bool BasicAuthentication::Authenticate(const HttpRequest &request)
{
	for (std::vector<BasicAuthRule*>::iterator it = _rules.begin(); it != _rules.end(); ++it)
	{
		BasicAuthRule *rule = *it;

		if (rule->Matches(request))
		{
			BasicAuthCredential user = ExtractAuth(request);

			std::map<BasicAuthCredential, std::string>::iterator auth = _users.find(user);
			if (auth == _users.end())
				return false;

			if (!rule->Authenticate(request, BasicAuthUser(*auth)))
				return false;
		}
	}

	return true;
}

HttpResponse* BasicAuthentication::UnauthorizedResponse(const HttpRequest &request)
{
	HttpHeader header;
	header["WWW-Authenticate"] = "Basic realm=\"\"";
	return new HttpResponse(HttpStatus(HTTP_STATUS_UNAUTHORIZED), header, "");
}

void BasicAuthentication::AddUser(const BasicAuthCredential &user, const std::string &roles)
{
	_users[user] = roles;
}

void BasicAuthentication::AddRule(BasicAuthRule *rule)
{
	_rules.push_back(rule);
}

BasicAuthCredential BasicAuthentication::ExtractAuth(const HttpRequest &request)
{
	static const std::string basic = "Basic ";

	HttpHeader::const_iterator it = request.GetHeader().find("Authorization");
	
	if (it == request.GetHeader().end())
		return BasicAuthCredential();

	std::string::size_type pos = it->second.find(basic);
	if (pos != 0)
		return BasicAuthCredential();

	std::string encoded = it->second.substr(basic.length());
	std::vector<char> decoded = Base64::Decode(encoded);

	std::string authstr(decoded.begin(), decoded.end());

	pos = authstr.find(':');
	if (pos == std::string::npos)
		return BasicAuthCredential();

	std::string user = authstr.substr(0, pos);
	std::string password = authstr.substr(pos + 1);

	return BasicAuthCredential(user, password);
}
