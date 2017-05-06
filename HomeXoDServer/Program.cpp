#include "HomeXoDServer.h"

int main(void)
{
	HomeXoDServer server;
	if (server.Init())
		server.Run();

	return 0;
}
