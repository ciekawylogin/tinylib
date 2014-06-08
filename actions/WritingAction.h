#ifndef WRITINGACTION_H
#define WRITINGACTION_H

#include "../sockets/Socket.h"
#include "Action.h"
#include "../API/EventListener.h"
#include "../threads/ListenerCallThread.h"
#include<memory>

typedef std::shared_ptr<Socket> Psocket;

class WritingAction : public Action
{
    std::shared_ptr<Socket> socket;
    const char *data;
    int dataSize;
    EventListener success;
    EventListener failure;
    //ListenerCallThread listener_call_thread;

public:
    WritingAction(Psocket socket, const char *data, int dataSize, EventListener success, EventListener failure, ListenerCallThread listener_call_thread);

    void perform();
};

#endif // WRITINGACTION_H
