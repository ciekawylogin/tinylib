#ifndef CLIENTCONNECTEDEVENT_H
#define CLIENTCONNECTEDEVENT_H

#include "Event.h"

class ClientConnectedEvent : public Event
{
public:
    ClientConnectedEvent(std::string);
};

#endif // CLIENTCONNECTEDEVENT_H
