#include "HttpRequest.h"

HttpRequest::HttpRequest()
: _method(REQUEST_METHOD_GET)
{
    
}

HttpRequest::HttpRequest(RequestMethod method, const std::string &url, const HttpHeader &header, const std::string &payload)
: _method(method)
, _url(url)
, _header(header)
, _payload(payload)
{
    
}

void HttpRequest::SetRequestMethod(RequestMethod method)
{
    _method = method;
}

void HttpRequest::SetRequestURL(const std::string &url)
{
    _url = url;
}

void HttpRequest::SetRequestHeader(const HttpHeader &header)
{
    _header = header;
}

void HttpRequest::SetRequestPayload(const std::string &payload)
{
    _payload = payload;
}

RequestMethod HttpRequest::GetMethod() const
{
    return _method;
}

const std::string& HttpRequest::GetURL() const
{
    return _url;
}

const HttpHeader& HttpRequest::GetHeader() const
{
    return _header;
}

const std::string& HttpRequest::GetPayload() const
{
    return _payload;
}

RequestURL HttpRequest::GetURL(const std::string &requestPath) const
{
    return RequestURL(_url, requestPath);
}
