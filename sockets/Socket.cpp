#include "Socket.h"
#include <exception>
#include "API/events/ClientConnectedEvent.h"
#include <unistd.h>

Socket::Socket()
{
    addrLen = sizeof(clientAddress);
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

int Socket::accept(EventListener evL)
{
    //trzeba bedzie w watku serwera zamykac nowy socket, a w watku obslugi polaczenia socket serwera
    int socket = ::accept(socketDescriptor, &clientAddress, &addrLen);
    if(socket == -1) throw std::runtime_error("accept() error.\n");
    //evL(ClientConnectedEvent("connected"));     //w tym evencie bedzie funkcja do odpalenia nowego watku?
    return socket;
}

void Socket::close()
{
    if(::close(socketDescriptor)!=0)
        throw std::runtime_error("Blad podczas zamykania polaczenia.\n");
}

void Socket::close(int sockFd)
{
    if(::close(sockFd)!=0)
        throw std::runtime_error("Blad podczas zamykania polaczenia.\n");
}
