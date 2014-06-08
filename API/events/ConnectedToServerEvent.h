#ifndef CONNECTEDTOSERVEREVENT_H
#define CONNECTEDTOSERVEREVENT_H

#include "Event.h"

class ConnectedToServerEvent : public Event
{
public:
    ConnectedToServerEvent(std::string);
    ~ConnectedToServerEvent(){}
};

#endif // CONNECTEDTOSERVEREVENT_H
