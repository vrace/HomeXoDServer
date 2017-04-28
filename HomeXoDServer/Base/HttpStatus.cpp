#include "HttpStatus.h"

HttpStatus::HttpStatus(HttpStatusCode statusCode)
: _statusCode(statusCode)
{
    InitReasonPhrase();
}

void HttpStatus::InitReasonPhrase()
{
    switch (_statusCode)
    {
        case HTTP_STATUS_OK:
            _phrase = "OK";
            break;
            
        case HTTP_STATUS_CREATED:
            _phrase = "Created";
            break;
            
        case HTTP_STATUS_ACCEPTED:
            _phrase = "Accepted";
            break;
            
        case HTTP_STATUS_NO_CONTENT:
            _phrase = "No Content";
            break;
            
        case HTTP_STATUS_BAD_REQEUST:
            _phrase = "Bad Request";
            break;
            
        case HTTP_STATUS_NOT_FOUND:
            _phrase = "Not Found";
            break;
            
        case HTTP_STATUS_INTERNAL_SERVER_ERROR:
            _phrase = "Internal Server Error";
            break;
            
        case HTTP_STATUS_NOT_IMPLEMENTED:
            _phrase = "Not Implemented";
            break;
            
        case HTTP_STATUS_SERVICE_UNAVAILABLE:
            _phrase = "Service Unavailable";
            break;
            
        default:
            _statusCode = HTTP_STATUS_NOT_IMPLEMENTED;
            InitReasonPhrase();
            break;
    }
}

HttpStatusCode HttpStatus::GetStatusCode() const
{
    return _statusCode;
}

const std::string& HttpStatus::GetReasonPhrase() const
{
    return _phrase;
}

std::ostream& operator <<(std::ostream &s, const HttpStatus &status)
{
    s << status.GetStatusCode();
    s << ' ';
    s << status.GetReasonPhrase();
    return s;
}
