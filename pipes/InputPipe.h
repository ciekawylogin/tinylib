#ifndef INPUTPIPE_H
#define INPUTPIPE_H

#include "Pipe.h"

class InputPipe : public Pipe
{
    int fd;
    InputPipe(int fd);
public:
    int read(char *buffer, int buffer_size) const;

    friend class Pipe;
};

#endif // INPUTPIPE_H
