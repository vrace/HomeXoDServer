#ifndef SIMPLE_WINSOCK_SERVER_H
#define SIMPLE_WINSOCK_SERVER_H

#include "../Base/RestServer.h"
#include <vector>
#include <Windows.h>
#include <WinSock2.h>

class SimpleWinSockServer : public RestServer
{
public:
	SimpleWinSockServer();

	virtual bool Init();
	void Run();
	void Shutdown();
	void PrepareShutdown();

protected:
	virtual const std::string& GetServerPort() const;
	virtual int GetServerRecvSize() const;

protected:
	SimpleWinSockServer(const SimpleWinSockServer&);
	SimpleWinSockServer& operator =(const SimpleWinSockServer&);

private:
	struct addrinfo* GetAddressInfo();
	SOCKET InitListener(struct addrinfo *addr);
	bool BindSocketAndListen(SOCKET fd, struct addrinfo *addr);
	void ServeClient(SOCKET fd);

private:
	std::vector<char> _recvbuf;
	SOCKET _listenfd;
	WSADATA _wsa;
	bool _shutdown;
};

#endif
