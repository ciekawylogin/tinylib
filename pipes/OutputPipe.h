#ifndef OUTPUTPIPE_H
#define OUTPUTPIPE_H

#include "Pipe.h"

class OutputPipe : public Pipe
{
    int fd;
    OutputPipe(int);
public:
    int write(const char *buffer, int buffer_size) const;

    friend class Pipe;
};

#endif // OUTPUTPIPE_H
