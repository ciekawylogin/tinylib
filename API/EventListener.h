#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "events/Event.h"

#include <functional>

typedef std::function<void(Event)> EventListener;

#endif // EVENTLISTENER_H
