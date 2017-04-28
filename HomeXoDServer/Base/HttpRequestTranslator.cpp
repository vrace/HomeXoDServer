#include "HttpRequestTranslator.h"
#include "RequestMethod.h"
#include "HttpHeader.h"
#include <sstream>

HttpRequest* HttpRequestTranslator::Translate(const std::string &request)
{
    std::stringstream ss(request);
    
    std::string line;
    if (!GetLine(ss, line) || line.empty())
        return NULL;
    
    RequestMethod method;
    std::string url;
    if (!ParseRequestMethodAndUrl(line, method, url))
        return NULL;
    
    HttpHeader header;
    
    while (ss && !line.empty())
    {
        if (GetLine(ss, line))
            AppendHeader(header, line);
    }
    
    std::stringstream payloadss;
    payloadss << ss.rdbuf();
    std::string payload = payloadss.str();
    
    return new HttpRequest(method, url, header, payload);
}

std::istream& HttpRequestTranslator::GetLine(std::istream &s, std::string &line)
{
    if (std::getline(s, line) && !line.empty())
    {
        std::string::size_type pos;
        
        pos = line.rfind('\r');
        if (pos != std::string::npos)
            line.erase(line.begin() + pos);
        
        pos = line.rfind('\n');
        if (pos != std::string::npos)
            line.erase(line.begin() + pos);
    }
    
    return s;
}

bool HttpRequestTranslator::ParseRequestMethodAndUrl(const std::string &line, RequestMethod &method, std::string &url)
{
    std::stringstream ss(line);
    
    std::string methodString;
    ss >> methodString;
    
    method = RequestMethodFromString(methodString);
    ss >> url;
    
    return !!ss;
}

void HttpRequestTranslator::AppendHeader(HttpHeader &header, const std::string &line)
{
    std::string::size_type delim = line.find(':');
    
    if (delim != std::string::npos)
    {
        std::string key = line.substr(0, delim);
        std::string value = line.substr(delim + 1);
        if (!value.empty() && value[0] == ' ')
            value.erase(value.begin());
        header[key] = value;
    }
}
