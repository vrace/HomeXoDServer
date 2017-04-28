#ifndef HTTP_REQUEST_TRANSLATOR_H
#define HTTP_REQUEST_TRANSLATOR_H

#include "HttpRequest.h"
#include "HttpHeader.h"
#include <string>

class HttpRequestTranslator
{
public:
    HttpRequest* Translate(const std::string &request);
    
private:
    std::istream& GetLine(std::istream &s, std::string &line);
    bool ParseRequestMethodAndUrl(const std::string &line, RequestMethod &method, std::string &url);
    void AppendHeader(HttpHeader &header, const std::string &line);
};

#endif
