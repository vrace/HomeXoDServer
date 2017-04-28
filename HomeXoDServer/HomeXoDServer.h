#ifndef HOME_XOD_SERVER_H
#define HOME_XOD_SERVER_H

#include "Network/SimpleWinSockServer.h"

class HomeXoDServer : public SimpleWinSockServer
{
public:
	bool Init();
};

#endif
