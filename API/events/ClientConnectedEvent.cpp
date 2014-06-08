#include "ClientConnectedEvent.h"

ClientConnectedEvent::ClientConnectedEvent(std::string message):
Event(message)
{
}


Connection *ClientConnectedEvent::getConnection()
{
    return connection;
}
