#ifndef SOCKET_H
#define SOCKET_H

#include "../API/EventListener.h"
#include "../sockets/Socket.h"
//#include "../sys/types.h"
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/**
 * @brief Zapewnia abstrakcję dla gniazd TCP, opakowując gniazda.
 */
class Socket
{

public:
    Socket();
    Socket(int,int,int,struct sockaddr*,int*,char);
    void bind();
    void listen();
    int read(char *, int);
    int write(const char *, int);
    void connect(std::string, int);
    void accept(EventListener);
    void setPort(int);
    void close();
    void close(int);
private:
    int socketDescriptor;
    int clientSocketDescriptor;
    int port;
    struct sockaddr clientAddress;
    unsigned int addrLen;
    bool isServer;
    char symKey;
    bool afterInit;
};

#endif // SOCKET_H
