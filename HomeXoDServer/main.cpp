#include "Common.h"
#include "Network/WSAInit.h"
#include "Network/HomeXoDServer.h"
#include "Controllers/MediaController.h"

int main()
{
	WSAInit wsaInit;
	HomeXoDServer server;

	if (!server.Initialize())
	{
		std::cout << "Unable to initialize server." << std::endl;
		return 1;
	}

	MediaController mediaController;

	server.SetMediaDelegate(&mediaController);
	server.Run();

	return 0;
}
