#include "ClientConnectedEvent.h"

ClientConnectedEvent::ClientConnectedEvent(std::string message, std::shared_ptr<Connection> connection):
    Event(message),
   connection(connection)
{
}

std::shared_ptr<Connection> ClientConnectedEvent::getConnection()
{
    return connection;
}
