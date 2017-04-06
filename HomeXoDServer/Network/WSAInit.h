#ifndef WSA_INIT_H
#define WSA_INIT_H

#include "../Common.h"

class WSAInit
{
public:
	WSAInit();
	~WSAInit();

	const WSADATA& WSAData() const;

private:
	WSAInit(const WSAInit&);
	WSAInit& operator =(const WSAInit&);

private:
	WSADATA _wsa;
};

#endif
