#include "ReadingAction.h"
#include <API/events/DataReadEvent.h>
#include <API/events/ReadingErrorEvent.h>

ReadingAction::ReadingAction(Socket *socket, char *data, int dataSize,
                             EventListener success, EventListener failure, ListenerCallThread listener_call_thread):
    socket(socket),
    data(data),
    dataSize(dataSize),
    success(success),
    failure(failure),
    listener_call_thread(listener_call_thread)
{
}

void ReadingAction::perform()
{
    try
    {
        socket->read(data, dataSize);
        DataReadEvent *event = new DataReadEvent("lol i just read some data :o");
        success(event);
    }
    catch (std::runtime_error error)
    {
        ReadingErrorEvent *event = new ReadingErrorEvent("Socket error while reading data");
        failure(event);
    }
}
