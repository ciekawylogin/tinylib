#ifndef INPUTPIPE_H
#define INPUTPIPE_H

#include "Pipe.h"
#include "../io/InputDescriptor.h"

class InputPipe : public Pipe, public InputDescriptor
{
    int fd;
    InputPipe(int fd);
public:
    int read(char *buffer, int buffer_size) const;
    int getUnixDescriptor() const;

    friend class Pipe;
};

#endif // INPUTPIPE_H
