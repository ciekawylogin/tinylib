#include "Server.h"

Server::Server(int port):
    socket(Socket())
{
    socket.setPort(port);
    socket.bind();
    socket.listen();
}

void Server::setConnectionListener(EventListener listener)
{
    this->listener = listener;
}

void Server::listenSync()
{
    while(true)
    {
        socket.accept(listener);

    }
}

void Server::addToBlackList(std::string ip)
{
    blackList.push_back(IP(ip));
}

 void Server::addToWhiteList(std::string ip)
 {
    whiteList.push_back(IP(ip));
 }

 bool Server::checkBlackList(std::string ip)
 {
     IP y = IP(ip);
     for(IP x: blackList)
     {
         if(x==y)
             return true;
     }
     return false;
 }

 bool Server::checkWhiteList(std::string ip)
 {
     IP y = IP(ip);
     for(IP x: whiteList)
     {
         if(x==y)
             return true;
     }
     return false;
 }

void Server::listenAsync()
{
    if(listener == nullptr)
    {
        throw new std::runtime_error("Cannot listen async when no listener is set!");
    }

    std::thread thread([this]()
    {
        listenSync();
    });
}
