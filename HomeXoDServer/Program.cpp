#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "HomeXoDServer.h"

int main(void)
{
	setlocale(LC_ALL, "zh-CN");

	HomeXoDServer server;
	if (server.Init())
		server.Run();

	return 0;
}
