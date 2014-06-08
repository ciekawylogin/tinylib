#ifndef FAILUREEVENT_H
#define FAILUREEVENT_H

#include "Event.h"

class FailureEvent: public Event
{
public:
    FailureEvent(std::string);
    ~FailureEvent(){}
};

#endif // FAILUREEVENT_H
