#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "events/Event.h"

#include <functional>
#include<memory>

typedef std::function<void(std::shared_ptr<Event>)> EventListener;


#endif // EVENTLISTENER_H
