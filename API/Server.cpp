#include "Server.h"

Server::Server():
    socket(Socket())
{
    socket.bind();
    socket.listen();
}

void Server::setConnectionListener(EventListener listener)
{
    this->listener = listener;
}

void Server::listenSync()
{

}

void Server::listenAsync()
{
    if(listener == nullptr)
    {
        throw new std::runtime_error("Cannot listen async when no listener is set!");
    }
    /*
    std::thread thread([]()
    {
        while(true)
        {
            socket.accept();
            listener();
        }
    });
    */
}

