#ifndef CONNECTION_H
#define CONNECTION_H

#include "EventListener.h"
#include "AsyncOperation.h"

class Connection
{
public:
    Connection();

    AsyncOperation writeAsync(const char *data, int dataSize, EventListener success, EventListener failure);
    AsyncOperation readAsync(char *data, int maxDataSize, EventListener success, EventListener failure);

    void writeSync(const char *data, int dataSize);
    void readSync(char *data, int maxDataSize);
};

#endif // CONNECTION_H
