#ifndef SERVER_H
#define SERVER_H

#include "EventListener.h"
#include <sockets/Socket.h>
#include <thread>

class Server
{
    EventListener listener;
    Socket socket;

public:
    Server();

    void setConnectionListener(EventListener);
    void listenSync();
    void listenAsync();

};

#endif // SERVER_H
