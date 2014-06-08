#ifndef SUCCESSEVENT_H
#define SUCCESSEVENT_H

#include "Event.h"

class SuccessEvent : public Event
{
public:
    SuccessEvent(std::string);
    ~SuccessEvent(){}
};

#endif // SUCCESSEVENT_H
