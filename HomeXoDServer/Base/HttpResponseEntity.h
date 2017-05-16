#ifndef HTTP_RESPONSE_ENTITY
#define HTTP_RESPONSE_ENTITY

#include "HttpResponse.h"

template <class EntityType>
class HttpResponseEntity : public HttpResponse
{
public:
	HttpResponseEntity(HttpStatusCode statusCode, const EntityType &entity)
		: HttpResponse(HttpStatus(statusCode), HttpHeaderWithContentType(entity.GetContentType()), entity.ToString())
	{

	}

	HttpResponseEntity(HttpStatusCode statusCode, const EntityType &entity, const std::string &contentType)
		: HttpResponse(HttpStatus(statusCode), HttpHeaderWithContentType(contentType), entity.ToString())
	{

	}
};

#endif
