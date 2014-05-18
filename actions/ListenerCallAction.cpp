#include "ListenerCallAction.h"

ListenerCallAction::ListenerCallAction(EventListener listener):
    listener(listener)
{
}

void ListenerCallAction::perform()
{
    listener();
}
