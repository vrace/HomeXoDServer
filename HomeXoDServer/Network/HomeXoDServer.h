#ifndef HOME_XOD_SERVER_H
#define HOME_XOD_SERVER_H

#include "../Delegates/MediaDelegate.h"
#include "../Delegates/ApplicationDelegate.h"

typedef struct HomeXoDServer HOME_XOD_SERVER;

HOME_XOD_SERVER* ServerAlloc(void);
HOME_XOD_SERVER* ServerInit(HOME_XOD_SERVER *server);
void ServerRelease(HOME_XOD_SERVER *server);

void ServerSetMediaDelegate(HOME_XOD_SERVER *server, MEDIA_DELEGATE *mediaDelegate);
void ServerSetApplicationDelegate(HOME_XOD_SERVER *server, APPLICATION_DELEGATE *applicationDelegate);

void ServerRun(HOME_XOD_SERVER *server);

#endif
