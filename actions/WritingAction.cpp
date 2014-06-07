#include "WritingAction.h"

WritingAction::WritingAction(Socket socket, char *data, int dataSize,
                             EventListener success, EventListener failure, ListenerCallThread listener_call_thread):
    socket(socket),
    data(data),
    dataSize(dataSize),
    success(success),
    failure(failure),
    listener_call_thread(listener_call_thread)
{
}

void WritingAction::perform()
{
    socket.write(data, dataSize);
}
