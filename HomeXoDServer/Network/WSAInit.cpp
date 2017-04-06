#include "../Common.h"
#include "WSAInit.h"

WSAInit::WSAInit()
{
	WSAStartup(MAKEWORD(2, 2), &_wsa);
}

WSAInit::~WSAInit()
{
	WSACleanup();
}

const WSADATA& WSAInit::WSAData() const
{
	return _wsa;
}
