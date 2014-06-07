#include "Event.h"

Event::Event(std::string message):
    message(message)
{
}

std::string Event::getMessage()
{
    return message;
}
