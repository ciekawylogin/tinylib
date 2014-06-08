#ifndef SERVERCONNECTION_H
#define SERVERCONNECTION_H

#include "Connection.h"

class ServerConnection: public Connection
{
public:
    ServerConnection(PConnect);
};

#endif // SERVERCONNECTION_H
