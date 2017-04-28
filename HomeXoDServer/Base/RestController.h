#ifndef REST_CONTROLLER_H
#define REST_CONTROLLER_H

#include "HttpRequest.h"
#include "HttpResponse.h"
#include <vector>
#include <string>

class RestController
{
public:
    RestController();
    virtual ~RestController();
    virtual HttpResponse* Dispatch(const HttpRequest &request) = 0;
};

#endif
