#ifndef LISTENERCALLACTION_H
#define LISTENERCALLACTION_H

#include "Action.h"
#include "../API/EventListener.h"

class ListenerCallAction : public Action
{
    EventListener listener;
    Event *event;
public:
    ListenerCallAction(EventListener, Event *);
    void perform();
};

#endif // LISTENERCALLACTION_H
