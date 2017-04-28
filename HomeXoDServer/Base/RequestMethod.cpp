#include "RequestMethod.h"

RequestMethod RequestMethodFromString(const std::string &methodString)
{
    if (methodString == "GET")
        return REQUEST_METHOD_GET;
    
    if (methodString == "HEAD")
        return REQUEST_METHOD_HEAD;
    
    if (methodString == "POST")
        return REQUEST_METHOD_POST;
    
    if (methodString == "PUT")
        return REQUEST_METHOD_PUT;
    
    if (methodString == "PATCH")
        return REQUEST_METHOD_PATCH;
    
    if (methodString == "DELETE")
        return REQUEST_METHOD_DELETE;
    
    return REQUEST_METHOD_INVALID;
}
