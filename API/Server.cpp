#include "Server.h"

Server::Server()
{
}

void Server::setConnectionListener(EventListener listener)
{
    this->listener = listener;
}
