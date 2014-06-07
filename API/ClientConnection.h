#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include "Connection.h"

class ClientConnection: public Connection
{
public:
    ClientConnection();
    void connect(std::string IP, int port);
};

#endif // CLIENTCONNECTION_H
