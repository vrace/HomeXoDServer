#ifndef APPLICATION_DELEGATE_H
#define APPLICATION_DELEGATE_H

#include "../Common.h"

class ApplicationDelegate
{
public:
	virtual void ApplicationList(bool refresh) = 0;
	virtual void ApplicationLaunch(int applicationId) = 0;
};

#endif
