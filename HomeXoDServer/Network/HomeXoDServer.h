#ifndef HOME_XOD_SERVER_H
#define HOME_XOD_SERVER_H

#include "../Common.h"
#include "../Delegates/MediaDelegate.h"
#include "../Delegates/ApplicationDelegate.h"

class HomeXoDServer
{
public:
	HomeXoDServer();
	~HomeXoDServer();

	bool Initialize();
	void SetMediaDelegate(MediaDelegate *media);
	void SetApplicationDelegate(ApplicationDelegate *application);

	void Run();

private:
	HomeXoDServer(const HomeXoDServer&);
	HomeXoDServer& operator =(const HomeXoDServer&);

private:
	SOCKET _listenfd;
	MediaDelegate *_mediaDelegate;
	ApplicationDelegate *_applicationDelegate;
};

#endif
