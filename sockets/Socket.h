#ifndef SOCKET_H
#define SOCKET_H

#include "../API/EventListener.h"
#include "../sockets/Socket.h"
//#include "../sys/types.h"
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../API/Server.h"

/**
 * @brief Zapewnia abstrakcję dla gniazd TCP, opakowując gniazda.
 */
class Socket
{
public:
    Socket();
    Socket(int, int, int, sockaddr_in *, int*, char);
    void bind();
    void listen();
    int read(char *, int);
    int write(const char *, int);
    void connect(std::string, int);
    void accept(EventListener, Server *server);
    void setPort(int);
    void close();
    void close(int);
private:
    Server * server;
    int socketDescriptor;
    int clientSocketDescriptor;
    int port;
    struct sockaddr_in clientAddress;
    unsigned int addrLen;
    bool isServer;
    char symKey;
    bool afterInit;
};

typedef std::shared_ptr<Socket> Psocket;

#endif // SOCKET_H
