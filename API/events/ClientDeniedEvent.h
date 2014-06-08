#ifndef CLIENTDENIEDEVENT_H
#define CLIENTDENIEDEVENT_H

#include "Event.h"

class ClientDeniedEvent : public Event
{
public:
    ClientDeniedEvent(std::string);
    ~ClientDeniedEvent(){}
};

#endif // CLIENTDENIEDEVENT_H
