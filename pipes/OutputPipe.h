#ifndef OUTPUTPIPE_H
#define OUTPUTPIPE_H

#include "Pipe.h"
#include "../io/OutputDescriptor.h"

class OutputPipe : public Pipe, public OutputDescriptor
{
    int fd;
    OutputPipe(int);
public:
    int write(const char *buffer, int buffer_size) const;
    int getUnixDescriptor() const;

    friend class Pipe;
};

#endif // OUTPUTPIPE_H
