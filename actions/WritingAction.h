#ifndef WRITINGACTION_H
#define WRITINGACTION_H

#include "../sockets/Socket.h"
#include "Action.h"
#include "../API/EventListener.h"

class WritingAction : public Action
{
    char *data;
    int dataSize;
    EventListener success;
    EventListener failure;

public:
    WritingAction(Socket socket, char *data, int dataSize, EventListener success, EventListener failure);

    void perform();
};

#endif // WRITINGACTION_H
