#include "HomeXoDServer.h"
#include "Base/BasicAuthentication/BasicAuthentication.h"
#include "Controller/SystemController.h"
#include "Controller/SystemControllerAuthentication.h"
#include "Controller/MediaController.h"

bool HomeXoDServer::Init()
{
	AddController(new SystemController());
	AddController(new MediaController());

	SetAuthentication(SetupAuthentication());

	return SimpleWinSockServer::Init();
}

AuthenticationManager* HomeXoDServer::SetupAuthentication()
{
	BasicAuthentication *auth = new BasicAuthentication();

	auth->AddUser(BasicAuthCredential("Admin", "Test1234"), "ADMIN|POWER USER|USER|GUEST");

	auth->AddRule(new SystemControllerAuthentication());

	return auth;
}
