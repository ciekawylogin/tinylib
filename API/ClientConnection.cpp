#include "ClientConnection.h"

ClientConnection::ClientConnection():
    Connection(PConnect(new Socket()))
{

}

void ClientConnection::connect(std::string IP, int port)
{
    socket->connect(IP, port);
    // cos jeszcze? :P
}
