#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event
{
    std::string message;
public:
    Event(std::string);
    std::string getMessage();
};

#endif // EVENT_H
