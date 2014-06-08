#include "InputPipe.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

InputPipe::InputPipe(int fd):
    fd(fd)
{
}

int InputPipe::read(char *buffer, int buffer_size) const
{
    return ::read(fd, buffer, buffer_size);
}

int InputPipe::getUnixDescriptor() const
{
    return fd;
}
