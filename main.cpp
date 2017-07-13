#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <exception>

#include <stdio.h>
#include <pthread.h>
#include <curl/curl.h>
#include <regex>

#include "util.h"
#include "HTTPDownloader.hpp"
#include "thread_pool.hpp"

#include "boost/algorithm/string.hpp"

using namespace std;

const int num_threads = 400;


vector<string> socks4List;

bool loadProxyList(string file)
{
    socks4List.clear();

    ifstream ifs(file, ios::in);
    if(!ifs)
        return false;

    for (std::string line; std::getline( ifs, line ); )
        socks4List.push_back( line );
    ifs.close();

    if(socks4List.size() > 0)
        return true;
    else
        return false;
}

std::string sendPost(string proxy)
{
    HTTPDownloader dl;
    string source, result;

    for(int i=0; i<=1; i++)
    {
        if(dl.download(proxy, "http"))
        {
            return proxy + ": Success!\n";
        }
        else if(dl.download(proxy, "socks4"))
        {
            return proxy + ": Success!\n";
        }
        else if(dl.download(proxy, "socks5"))
        {
            return proxy + ": Success!\n";
        }
        else if(dl.download(proxy, "socks4a"))
        {
            return proxy + ": Success!\n";
        }
        else if(dl.download(proxy, "http10"))
        {
            return proxy + ": Success!\n";
        }
    }
    return proxy + ": Failed!\n";
}

int main(int argc, char* argv[])
{
    if(!loadProxyList("proxy.txt"))
    {
        cout << "No proxy list loaded!";
        return -1;
    }

    thread_pool pool(num_threads);
    list<future<string>> results;

    int from = 0;
    int to = socks4List.size() - 1;

    cout << "Starting from "<<from<<" to "<<to<<endl;

    for(int i=from; i<=to; i++)
    {
        string proxy = socks4List[i];
        try
        {
            std::future<string> buff = pool.async( function<string(string)>(sendPost), std::string(proxy) );
            results.push_back( std::move(buff) );
        }
        catch(exception &e)
        {
            cout << e.what();
            cout << "\n*** ERROR ***"<<endl;
            getchar();
        }
    }

    cout <<"Sending requests async..."<<endl;
    for(auto i=results.begin(); i != results.end(); i++)
    {
        static int k=0;

        try
        {
            string result = i->get();
            cout<<"["<<k++<<"] "<<result;
        }
        catch(exception &e)
        {
            cout << e.what();
            cout << "\n*** ERROR ***"<<endl;
            getchar();
        }
    }
    //*/

    cout<<endl<<"Finished!"<<endl;
    system("pause");
    return 0;
}


