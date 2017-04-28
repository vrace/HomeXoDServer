#ifndef REQUEST_METHOD_H
#define REQUEST_METHOD_H

#include <string>

enum RequestMethod
{
    REQUEST_METHOD_INVALID,
    
    REQUEST_METHOD_GET,
    REQUEST_METHOD_HEAD,
    REQUEST_METHOD_POST,
    REQUEST_METHOD_PUT,
    REQUEST_METHOD_PATCH,
    REQUEST_METHOD_DELETE,
};

RequestMethod RequestMethodFromString(const std::string &methodString);

#endif
