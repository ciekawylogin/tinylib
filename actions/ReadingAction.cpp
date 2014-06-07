#include "ReadingAction.h"

ReadingAction::ReadingAction(Socket socket, char *data, int dataSize,
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
    socket.read(data, dataSize);
}
