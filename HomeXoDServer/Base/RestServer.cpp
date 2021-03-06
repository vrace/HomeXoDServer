#include "RestServer.h"

RestServer::RestServer()
	: _authentication(NULL)
{
    
}

RestServer::~RestServer()
{
    for (std::vector<RestController*>::iterator it = _controllers.begin(); it != _controllers.end(); ++it)
        delete *it;

	if (_authentication)
		delete _authentication;
}

void RestServer::AddController(RestController *controller)
{
    _controllers.push_back(controller);
}

std::string RestServer::Dispatch(const std::string &request)
{
    HttpRequest *httpRequest = _requestTranslator.Translate(request);
    HttpResponse *httpResponse = NULL;
    
    if (!httpRequest)
    {
        httpResponse = BadRequest();
    }
    else
    {
		if (_authentication && !_authentication->Authenticate(*httpRequest))
			httpResponse = _authentication->UnauthorizedResponse(*httpRequest);

        for (std::vector<RestController*>::iterator it = _controllers.begin(); !httpResponse && it != _controllers.end(); ++it)
            httpResponse = (*it)->Dispatch(*httpRequest);
        
        if (!httpResponse)
            httpResponse = DefaultResponse();
    }
    
    std::string response = _responseTranslator.Translate(*httpResponse);
    
    if (httpRequest)
        delete httpRequest;
    
    if (httpResponse)
        delete httpResponse;
    
    return response;
}

HttpResponse* RestServer::DefaultResponse()
{
    return new HttpResponse(HttpStatus(HTTP_STATUS_NOT_FOUND));
}

HttpResponse* RestServer::BadRequest()
{
    return new HttpResponse(HttpStatus(HTTP_STATUS_BAD_REQEUST));
}

void RestServer::SetAuthentication(AuthenticationManager *auth)
{
	_authentication = auth;
}
