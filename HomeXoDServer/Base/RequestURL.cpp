#include "RequestURL.h"
#include <sstream>

RequestURL::RequestURL(const std::string &url, const std::string &requestPath)
: _url(url)
, _valid(false)
{
    if (url == requestPath || url.find(requestPath + '/') == 0)
    {
        std::stringstream ss(url.substr(requestPath.length()));
        
        std::string line;
        while (std::getline(ss, line, '/'))
        {
            if (!line.empty())
                _components.push_back(line);
        }
        
        _valid = true;
    }
}

RequestURL::operator bool() const
{
    return _valid;
}

RequestURL::operator const std::string&() const
{
    return _url;
}

const std::string& RequestURL::operator [](int index) const
{
    return _components[index];
}

int RequestURL::GetComponentSize() const
{
    return (int)_components.size();
}
