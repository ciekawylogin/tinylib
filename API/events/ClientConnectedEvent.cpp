#include "ClientConnectedEvent.h"

ClientConnectedEvent::ClientConnectedEvent(std::string message, Connection *connection):
    Event(message),
    connection(connection)
{
}

Connection *ClientConnectedEvent::getConnection()
{
    return connection;
}
