#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include "RequestMethod.h"
#include "RequestURL.h"
#include "HttpHeader.h"
#include <string>

class HttpRequest
{
public:
    HttpRequest();
    HttpRequest(RequestMethod method, const std::string &url, const HttpHeader &header, const std::string &payload);
    
    void SetRequestMethod(RequestMethod method);
    void SetRequestURL(const std::string &url);
    void SetRequestHeader(const HttpHeader &header);
    void SetRequestPayload(const std::string &payload);
    
    RequestMethod GetMethod() const;
    const std::string& GetURL() const;
    const HttpHeader& GetHeader() const;
    const std::string& GetPayload() const;
    
    RequestURL GetURL(const std::string &requestPath) const;
    
private:
    RequestMethod _method;
    std::string _url;
    std::string _payload;
    HttpHeader _header;
};

#endif
