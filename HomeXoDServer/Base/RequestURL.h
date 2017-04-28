#ifndef REQUEST_URL_H
#define REQUEST_URL_H

#include <vector>
#include <string>

class RequestURL
{
public:
    RequestURL(const std::string &url, const std::string &requestPath);
    
    operator bool() const;
    operator const std::string&() const;
    const std::string& operator [](int index) const;
    
    int GetComponentSize() const;
    
private:
    bool _valid;
    std::string _url;
    std::vector<std::string> _components;
};

#endif
