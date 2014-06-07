#ifndef CLIENTCONNECTEDEVENT_H
#define CLIENTCONNECTEDEVENT_H

#include "Event.h"

class ClientConnectedEvent : public Event
{
public:
    ClientConnectedEvent(std::string);

    int oldSocket;
    int newSocket;
};

#endif // CLIENTCONNECTEDEVENT_H
