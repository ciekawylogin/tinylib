#include "Socket.h"
#include <exception>

Socket::Socket()
{
    socketDescriptor=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(socketDescriptor==-1) throw std::runtime_error("Nie można utworzyc gniazda.\n");
}

void Socket::setPort(int port)
{
    this->port=port;
}

void Socket::bind()
{
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    name.sin_port = htons((short)port);

    if(::bind(socketDescriptor, (struct sockaddr*)&name, sizeof(name))!=0)
        throw std::runtime_error("Bind() nie powiodl sie.\n");
}

void Socket::listen()
{
    if(::listen(socketDescriptor, 128)!=0)
        throw std::runtime_error("Blad \"stowarzyszenia\" (listen()).\n");
}

void Socket::connect(int addr, int port)
{
    struct sockaddr_in name;
    name.sin_family = AF_INET;
    name.sin_addr.s_addr = htonl(addr);
    name.sin_port = htons((short)port);

    if(::connect(socketDescriptor,(struct sockaddr*)&name, sizeof(name))!=0)
        throw std::runtime_error("Nie mozna zestawic polaczenia z dana maszyna.\n");
}


