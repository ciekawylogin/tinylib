#include "Server.h"
#include "../API/SecurityPolicy.h"
#include "../sockets/Socket.h"
#include <poll.h>
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
        struct pollfd pfd;
            pfd.fd = connections.back()->getSocket().getSocket();
            pfd.events = POLLIN | POLLHUP | POLLRDNORM;
            pfd.revents = 0;
            while (pfd.revents == 0) {
                // call poll with a timeout of 100 ms
                if (poll(&pfd, 1, 100) > 0) {
                    // if result > 0, this means that there is either data available on the
                    // socket, or the socket has been closed
                    char buffer[32];
                    if (recv(pfd.fd, buffer, sizeof(buffer), MSG_PEEK | MSG_DONTWAIT) == 0) {
                        // if recv returns zero, that means the connection has been closed:
                        // kill the child process
                        //kill(childProcess, SIGKILL);
                        //waitpid(childProcess, &status, WNOHANG);
                        //close(fd);
                        // do something else, e.g. go on vacation
                    std::cout<<"rozlaczono";
                    }
                }
            }
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
