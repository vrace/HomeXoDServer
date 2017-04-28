#include "HttpResponse.h"

HttpResponse::HttpResponse()
: _status(HttpStatus(HTTP_STATUS_OK))
{
    
}

HttpResponse::HttpResponse(const HttpStatus &status)
: _status(status)
{
    
}

HttpResponse::HttpResponse(const HttpStatus &status, const HttpHeader &header, const std::string &payload)
: _status(status)
, _header(header)
, _payload(payload)
{
    
}

void HttpResponse::SetStatus(const HttpStatus &status)
{
    _status = status;
}

void HttpResponse::SetHeader(const HttpHeader &header)
{
    _header = header;
}

void HttpResponse::SetPayload(const std::string &payload)
{
    _payload = payload;
}

const HttpStatus& HttpResponse::GetStatus() const
{
    return _status;
}

const HttpHeader& HttpResponse::GetHeader() const
{
    return _header;
}

const std::string& HttpResponse::GetPayload() const
{
    return _payload;
}
