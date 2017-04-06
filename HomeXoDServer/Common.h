#ifndef COMMON_H
#define COMMON_H

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <Windows.h>

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <IPHlpApi.h>

#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <iomanip>

#endif
