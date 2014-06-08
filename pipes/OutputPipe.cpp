#include "OutputPipe.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

OutputPipe::OutputPipe(int fd):
    fd(fd)
{
}

int OutputPipe::write(const char *buffer, int buffer_size) const
{
    return ::write(fd, buffer, buffer_size);
}
