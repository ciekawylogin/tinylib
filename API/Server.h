#ifndef SERVER_H
#define SERVER_H

#include <API/EventListener.h>

class Server
{
    EventListener listener;
public:
    Server();

    void setConnectionListener(EventListener);
    void listen();

};

#endif // SERVER_H
