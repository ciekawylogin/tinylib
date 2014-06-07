#ifndef WRITINGERROREVENT_H
#define WRITINGERROREVENT_H

#include "FailureEvent.h"

class WritingErrorEvent : public FailureEvent
{
public:
    WritingErrorEvent(std::string);
};

#endif // WRITINGERROREVENT_H
