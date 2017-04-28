#ifndef HTTP_STATUS_H
#define HTTP_STATUS_H

#include <string>
#include <ostream>

enum HttpStatusCode
{
    HTTP_STATUS_OK = 200,
    HTTP_STATUS_CREATED = 201,
    HTTP_STATUS_ACCEPTED = 202,
    HTTP_STATUS_NO_CONTENT = 204,
    
    HTTP_STATUS_BAD_REQEUST = 400,
    HTTP_STATUS_NOT_FOUND = 404,
    
    HTTP_STATUS_INTERNAL_SERVER_ERROR = 500,
    HTTP_STATUS_NOT_IMPLEMENTED = 501,
    HTTP_STATUS_SERVICE_UNAVAILABLE = 503,
};

class HttpStatus
{
public:
    HttpStatus(HttpStatusCode statusCode);
    
    HttpStatusCode GetStatusCode() const;
    const std::string& GetReasonPhrase() const;
    
private:
    void InitReasonPhrase();
    
private:
    HttpStatusCode _statusCode;
    std::string _phrase;
};

std::ostream& operator <<(std::ostream &s, const HttpStatus &status);

#endif
