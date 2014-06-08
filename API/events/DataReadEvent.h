#ifndef DATAREADEVENT_H
#define DATAREADEVENT_H

#include "SuccessEvent.h"

class DataReadEvent : public SuccessEvent
{
public:
    DataReadEvent(std::string);
    ~DataReadEvent(){}
};

#endif // DATAREADEVENT_H
