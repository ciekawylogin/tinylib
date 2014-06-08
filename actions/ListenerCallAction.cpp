#include "ListenerCallAction.h"

ListenerCallAction::ListenerCallAction(EventListener listener, PEvent event):
    listener(listener),
    event(event)
{
}

void ListenerCallAction::perform()
{
    listener(event);
}
