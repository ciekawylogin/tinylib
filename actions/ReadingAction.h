#ifndef READINGACTION_H
#define READINGACTION_H

#include "Action.h"
#include "../API/EventListener.h"
#include "../sockets/Socket.h"
#include "../threads/ListenerCallThread.h"
#include<memory>


typedef std::shared_ptr<Socket> Psocket;
class ReadingAction : public Action
{
    Psocket socket;
    char *data;
    int dataSize;
    EventListener success;
    EventListener failure;
    //ListenerCallThread listener_call_thread;

public:
    ReadingAction(Psocket socket, char *data, int dataSize, EventListener success, EventListener failure, ListenerCallThread listener_call_thread);

    void perform();
};

#endif // READINGACTION_H
