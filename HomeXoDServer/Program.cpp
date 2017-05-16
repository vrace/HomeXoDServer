#include "HomeXoDServer.h"

HomeXoDServer theServer;

int main(void)
{
	if (theServer.Init())
	{
		theServer.Run();
		theServer.Shutdown();
	}

	return 0;
}
