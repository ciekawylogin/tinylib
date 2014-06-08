#include "Select.h"
#include <algorithm>
#include <cstdlib>

Select::Select()
{
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    FD_ZERO(&exceptfds);
}

void Select::addInputDescriptor(InputDescriptor &descriptor)
{
    FD_SET(descriptor.getUnixDescriptor(), &readfds);
    maxfd = std::max(maxfd, descriptor.getUnixDescriptor());
}

void Select::addOutputDescriptor(OutputDescriptor &descriptor)
{
    FD_SET(descriptor.getUnixDescriptor(), &writefds);
    maxfd = std::max(maxfd, descriptor.getUnixDescriptor());
}

Descriptor*Select::operator()()
{
    return descriptors.at(::select(maxfd + 1, &readfds, &writefds, &exceptfds, (struct timeval*) 0));
}
