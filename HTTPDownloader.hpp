#ifndef HTTPDOWNLOADER_HPP_INCLUDED
#define HTTPDOWNLOADER_HPP_INCLUDED

#include <string>

class HTTPDownloader
{
public:
    HTTPDownloader();
    ~HTTPDownloader();
    bool download(std::string proxy, std::string proxyType);

private:
    void* curl;
};

#endif // HTTPDOWNLOADER_HPP_INCLUDED
