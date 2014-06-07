#include "WritingAction.h"

WritingAction::WritingAction(char *data, int dataSize, EventListener success, EventListener failure):
    data(data),
    dataSize(dataSize),
    success(success),
    failure(failure)
{
}

void WritingAction::perform(Socket socket)
{
    socket.write(data)
}
