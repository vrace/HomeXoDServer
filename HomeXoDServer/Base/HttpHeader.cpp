#include "HttpHeader.h"

const std::string HEADER_CONTENT_TYPE = "Content-Type";

const std::string CONTENT_TYPE_TEXT = "text";
const std::string CONTENT_TYPE_MULTIPART = "multipart";
const std::string CONTENT_TYPE_MESSAGE = "message";
const std::string CONTENT_TYPE_IMAGE = "image";
const std::string CONTENT_TYPE_AUDIO = "audio";
const std::string CONTENT_TYPE_VIDEO = "video";
const std::string CONTENT_TYPE_APPLICATION = "application";

std::string CreateContentType(const std::string &type, const std::string &subtype)
{
	return type + "/" + subtype;
}

void SetContentType(HttpHeader &header, const std::string &contentType)
{
	header[HEADER_CONTENT_TYPE] = contentType;
}

void SetContentType(HttpHeader &header, const std::string &type, const std::string &subtype)
{
	SetContentType(header, CreateContentType(type, subtype));
}

HttpHeader HttpHeaderWithContentType(const std::string &contentType)
{
	HttpHeader header;
	SetContentType(header, contentType);
	return header;
}
