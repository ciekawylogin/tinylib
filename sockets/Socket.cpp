#include "Socket.h"
#include <exception>

Socket::Socket()
{
    socketDescriptor=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socketDescriptor==-1) throw std::runtime_error("Nie można utworzyc gniazda.\n");
}

void Socket::setPort(int port)
{
    this->port=(short int)port;
}

void Socket::bind()
{
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    name.sin_port = htons(port);

    if(::bind(socketDescriptor, (struct sockaddr*)&(name), sizeof(name))!=0)
        throw std::runtime_error("Bind() nie powiodl sie.\n");
}
