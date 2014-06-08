#ifndef CLIENTCONNECTEDEVENT_H
#define CLIENTCONNECTEDEVENT_H

#include "Event.h"
#include "../Connection.h"
#include<memory>

class ClientConnectedEvent : public Event
{
    std::shared_ptr<Connection> connection;
public:
    ClientConnectedEvent(std::string, std::shared_ptr<Connection> connection);
    std::shared_ptr<Connection> getConnection();
};

#endif // CLIENTCONNECTEDEVENT_H
