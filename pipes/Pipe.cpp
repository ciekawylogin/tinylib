#include "Pipe.h"
#include "InputPipe.h"
#include "OutputPipe.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdexcept>

Pipe::Pipe()
{
}

std::pair<InputPipe, OutputPipe> Pipe::createPipesPair()
{
    int fd[2];
    int result = pipe(fd);
    if(result == -1)
    {
        throw new std::runtime_error("cannot create a pipe");
    }
    return std::make_pair(InputPipe(fd[0]), OutputPipe(fd[1]));
}

