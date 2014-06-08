#ifndef PIPE_H
#define PIPE_H

#include <utility>

class InputPipe;
class OutputPipe;

class Pipe
{
protected:
    Pipe();
public:
    static std::pair<InputPipe, OutputPipe>createPipesPair();
    virtual int getUnixDescriptor() const = 0;
};

#endif // PIPE_H
