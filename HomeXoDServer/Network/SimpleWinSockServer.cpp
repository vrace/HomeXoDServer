#include "SimpleWinSockServer.h"
#include <WS2tcpip.h>
#include <IPHlpApi.h>

SimpleWinSockServer::SimpleWinSockServer()
	: _listenfd(INVALID_SOCKET)
	, _shutdown(false)
{

}

addrinfo* SimpleWinSockServer::GetAddressInfo()
{
	addrinfo *result, hints;

	result = NULL;
	memset(&hints, 0, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, GetServerPort().c_str(), &hints, &result);
	return result;
}

SOCKET SimpleWinSockServer::InitListener(addrinfo *addr)
{
	SOCKET fd = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
	
	if (!BindSocketAndListen(fd, addr))
	{
		closesocket(fd);
		fd = INVALID_SOCKET;
	}

	return fd;
}

bool SimpleWinSockServer::BindSocketAndListen(SOCKET fd, addrinfo *addr)
{
	if (bind(fd, addr->ai_addr, addr->ai_addrlen) == SOCKET_ERROR)
		return false;

	if (listen(fd, SOMAXCONN) == SOCKET_ERROR)
		return false;

	return true;
}

bool SimpleWinSockServer::Init()
{
	if (WSAStartup(MAKEWORD(2, 2), &_wsa) != 0)
		return false;

	addrinfo *addr = GetAddressInfo();
	if (!addr)
		return false;

	_listenfd = InitListener(addr);
	freeaddrinfo(addr);

	return _listenfd != INVALID_SOCKET;
}

void SimpleWinSockServer::Shutdown()
{
	if (_listenfd != INVALID_SOCKET)
		closesocket(_listenfd);

	WSACleanup();
}

void SimpleWinSockServer::PrepareShutdown()
{
	_shutdown = true;
}

void SimpleWinSockServer::Run()
{
	while (!_shutdown)
	{
		SOCKET clientfd = accept(_listenfd, NULL, NULL);
		
		if (clientfd == INVALID_SOCKET)
			continue;

		ServeClient(clientfd);
		closesocket(clientfd);
	}
}

void SimpleWinSockServer::ServeClient(SOCKET fd)
{
	_recvbuf.resize(GetServerRecvSize());
	
	int res = recv(fd, &_recvbuf[0], GetServerRecvSize(), 0);
	
	if (res > 0)
	{
		std::string request(&_recvbuf[0], res);
		std::string response = Dispatch(request);
		send(fd, response.c_str(), response.length(), 0);
	}
}

const std::string& SimpleWinSockServer::GetServerPort() const
{
	static const std::string SERVER_PORT = "17123";
	return SERVER_PORT;
}

int SimpleWinSockServer::GetServerRecvSize() const
{
	return 1048576 * 10;
}
