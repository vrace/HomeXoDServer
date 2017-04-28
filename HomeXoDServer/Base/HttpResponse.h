#ifndef HTTP_RESPONSE_H
#define HTTP_RESPONSE_H

#include "HttpStatus.h"
#include "HttpHeader.h"

class HttpResponse
{
public:
    HttpResponse();
    HttpResponse(const HttpStatus &status);
    HttpResponse(const HttpStatus &status, const HttpHeader &header, const std::string &payload);
    
    void SetStatus(const HttpStatus &status);
    void SetHeader(const HttpHeader &header);
    void SetPayload(const std::string &payload);
    
    const HttpStatus& GetStatus() const;
    const HttpHeader& GetHeader() const;
    const std::string& GetPayload() const;
    
private:
    HttpStatus _status;
    HttpHeader _header;
    std::string _payload;
};

#endif
