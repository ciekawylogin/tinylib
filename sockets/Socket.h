#ifndef SOCKET_H
#define SOCKET_H

#include "API/EventListener.h"
#include "sys/socket.h"
#include "sys/types.h"
#include <netdb.h>
#include <netinet/in.h>

/**
 * @brief Zapewnia abstrakcję dla gniazd TCP, opakowując gniazda linuksowe bądź windowsowe.
 *
 * Implementacja metod tej klasy jest zależna od systemu, na którym jest kompilowana.
 * Interfejs jest uniwersalny.
 */
class Socket
{
public:
    Socket();
    void bind();
    void listen();
    void connect(int, int);
    int accept(EventListener);
    void setPort(int);
    void close();
    void close(int);
private:
    int socketDescriptor;
    int port;
    struct sockaddr clientAddress;
    unsigned int addrLen;
};

#endif // SOCKET_H
