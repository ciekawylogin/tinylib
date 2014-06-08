#ifndef SELECT_H
#define SELECT_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "InputDescriptor.h"
#include "OutputDescriptor.h"
#include <map>

class Select
{
    fd_set readfds;
    fd_set writefds;
    fd_set exceptfds;

    int maxfd;

    std::map<int, Descriptor*> descriptors;
public:
    Select();

    void addInputDescriptor(InputDescriptor&descriptor);
    void addOutputDescriptor(OutputDescriptor&descriptor);

    Descriptor*operator()();
};

#endif // SELECT_H
