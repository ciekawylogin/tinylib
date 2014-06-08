#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include "Connection.h"

class ServerConnection: public Connection
{
public:
    ServerConnection(Socket *);
};

#endif // SERVERCONNECTION_H
