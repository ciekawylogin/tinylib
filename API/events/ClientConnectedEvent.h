#ifndef CLIENTCONNECTEDEVENT_H
#define CLIENTCONNECTEDEVENT_H

#include "Event.h"
#include "../Connection.h"

class ClientConnectedEvent : public Event
{
    Connection *connection;
public:
    ClientConnectedEvent(std::string, Connection *connection);
    Connection *getConnection();
};

#endif // CLIENTCONNECTEDEVENT_H
