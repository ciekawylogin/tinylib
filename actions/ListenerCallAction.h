#ifndef LISTENERCALLACTION_H
#define LISTENERCALLACTION_H

#include "Action.h"
#include "../API/EventListener.h"

class ListenerCallAction : public Action
{
    EventListener listener;
    PEvent event;
public:
    ListenerCallAction(EventListener, PEvent);
    void perform();
};

#endif // LISTENERCALLACTION_H
