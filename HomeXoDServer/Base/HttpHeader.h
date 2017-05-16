#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

#include <map>
#include <string>

typedef std::map<std::string, std::string> HttpHeader;

extern const std::string HEADER_CONTENT_TYPE;
extern const std::string CONTENT_TYPE_TEXT;
extern const std::string CONTENT_TYPE_MULTIPART;
extern const std::string CONTENT_TYPE_MESSAGE;
extern const std::string CONTENT_TYPE_IMAGE;
extern const std::string CONTENT_TYPE_AUDIO;
extern const std::string CONTENT_TYPE_VIDEO;
extern const std::string CONTENT_TYPE_APPLICATION;

std::string CreateContentType(const std::string &type, const std::string &subtype);
void SetContentType(HttpHeader &header, const std::string &contentType);
void SetContentType(HttpHeader &header, const std::string &type, const std::string &subtype);

HttpHeader HttpHeaderWithContentType(const std::string &contentType);

#endif
