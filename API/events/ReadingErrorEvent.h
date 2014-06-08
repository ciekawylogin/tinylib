#ifndef READINGERROREVENT_H
#define READINGERROREVENT_H

#include "FailureEvent.h"

class ReadingErrorEvent : public FailureEvent
{
public:
    ReadingErrorEvent(std::string);
    ~ReadingErrorEvent(){}
};

#endif // READINGERROREVENT_H
