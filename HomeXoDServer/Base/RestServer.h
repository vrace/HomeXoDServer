#ifndef REST_SERVER_H
#define REST_SERVER_H

#include "RestController.h"
#include "HttpRequestTranslator.h"
#include "HttpResponseTranslator.h"
#include "AuthenticationManager.h"
#include <string>
#include <vector>

class RestServer
{
public:
    RestServer();
    virtual ~RestServer();
    
	void SetAuthentication(AuthenticationManager *auth);
    void AddController(RestController *controller);
    std::string Dispatch(const std::string &request);
    
protected:
    virtual HttpResponse* DefaultResponse();
    HttpResponse* BadRequest();
    
private:
    RestServer(const RestServer&);
    RestServer& operator =(const RestServer&);
    
private:
    HttpRequestTranslator _requestTranslator;
    HttpResponseTranslator _responseTranslator;
	AuthenticationManager *_authentication;
    std::vector<RestController*> _controllers;
};

#endif
