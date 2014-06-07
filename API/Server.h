#ifndef SERVER_H
#define SERVER_H

#include "EventListener.h"
#include <sockets/Socket.h>
#include <thread>
#include <vector>
#include "IP.h"
#include<string>

class Server
{
    EventListener listener;
    Socket socket;
    std::vector<IP> blackList;
    std::vector<IP> whiteList;


public:
    Server();

    void addToWhiteList(std::string ip);
    void addToBlackList(std::string ip);
    bool checkBlackList(std::string);
    bool checkWhiteList(std::string);
    void setConnectionListener(EventListener);
    void listenSync();
    void listenAsync();

};

#endif // SERVER_H
