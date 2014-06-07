#include "ListenerCallAction.h"

ListenerCallAction::ListenerCallAction(EventListener listener, Event *event):
    listener(listener),
    event(event)
{
}

void ListenerCallAction::perform()
{
    listener(event);
}
