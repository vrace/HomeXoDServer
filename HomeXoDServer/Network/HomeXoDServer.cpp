#include "../Common.h"
#include "HomeXoDServer.h"

HomeXoDServer::HomeXoDServer()
	: _listenfd(INVALID_SOCKET)
	, _mediaDelegate(NULL)
	, _applicationDelegate(NULL)
{

}

HomeXoDServer::~HomeXoDServer()
{
	if (_listenfd != INVALID_SOCKET)
		closesocket(_listenfd);
}

bool HomeXoDServer::Initialize()
{
	return true;
}

void HomeXoDServer::SetMediaDelegate(MediaDelegate *media)
{
	_mediaDelegate = media;
}

void HomeXoDServer::SetApplicationDelegate(ApplicationDelegate *application)
{
	_applicationDelegate = application;
}

void HomeXoDServer::Run()
{

}
