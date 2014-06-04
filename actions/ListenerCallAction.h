#ifndef LISTENERCALLACTION_H
#define LISTENERCALLACTION_H

#include "Action.h"
#include "../API/EventListener.h"

class ListenerCallAction : public Action
{
    EventListener listener;
public:
    ListenerCallAction(EventListener);
    void perform(Event);
};

#endif // LISTENERCALLACTION_H
