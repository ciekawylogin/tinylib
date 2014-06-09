#include "ReadingAction.h"
#include <API/events/DataReadEvent.h>
#include <API/events/ReadingErrorEvent.h>

ReadingAction::ReadingAction(Psocket socket, char *data, int dataSize,
                             EventListener success, EventListener failure, ListenerCallThread listener_call_thread):
    socket(socket),
    data(data),
    dataSize(dataSize),
    success(success),
    failure(failure)//,
    //listener_call_thread(listener_call_thread)
{
}

void ReadingAction::perform()
{
    try
    {
        socket->read(data, dataSize);
        std::shared_ptr<DataReadEvent> event (new DataReadEvent("Data read."));
        success(event);
    }
    catch (std::runtime_error error)
    {
        std::shared_ptr<ReadingErrorEvent> event (new ReadingErrorEvent(std::string("Socket error while reading data: ") + error.what()));
        failure(event);
    }
}
