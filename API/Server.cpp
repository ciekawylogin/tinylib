#include "Server.h"
#include "../API/SecurityPolicy.h"
#include "../sockets/Socket.h"
#include <iostream>
#include "ServerConnection.h"

Server::Server(int port):
    socket(new Socket())
{
    policy = SecurityPolicy::ACCEPT_ALL_EXCEPT_LISTED;
    socket->setPort(port);
    socket->bind();
    socket->listen();
}

void Server::setConnectionListener(EventListener listener)
{
    this->listener = listener;
}

bool Server::canConnect(std::string ip)
{
    if(policy == SecurityPolicy::ACCEPT_ALL_EXCEPT_LISTED)
        return !checkBlackList(ip);
    else
        return checkWhiteList(ip);
}
void Server::listenSync()
{
    while(true)
    {
        socket->accept(listener, this);
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
    std::thread *thread = new std::thread([this]()
    {
        listenSync();
    });
}

void Server::setSecurityPolicy(SecurityPolicy policy)
{
	this->policy = policy;
}

std::shared_ptr<ServerConnection> Server::listenForOneClient()
{
    if(listener == nullptr || listener == NULL)
    {
        listener = [](PEvent){};
    }
    socket->accept(listener, this);
    return connections.back();
}
