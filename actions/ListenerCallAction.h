#ifndef LISTENERCALLACTION_H
#define LISTENERCALLACTION_H

#include "Action.h"
#include "../API/EventListener.h"

class ListenerCallAction : public Action
{
public:
    ListenerCallAction(EventListener);
    void perform();
};

#endif // LISTENERCALLACTION_H
