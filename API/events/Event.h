#ifndef EVENT_H
#define EVENT_H
#include<memory>

#include <string>

class Event
{
    std::string message;
public:
    Event(std::string);
    std::string getMessage();
};

typedef std::shared_ptr<Event> PEvent;

#endif // EVENT_H
