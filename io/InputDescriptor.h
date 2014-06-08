#ifndef INPUTDESCRIPTOR_H
#define INPUTDESCRIPTOR_H

#include "Descriptor.h"

/**
 * @brief Interface for InputPipe or (Input)Socket
 */
class InputDescriptor: public Descriptor
{
protected:
    InputDescriptor();
public:
    virtual int read(char *buffer, int buffer_size) const = 0;
};

#endif // INPUTDESCRIPTOR_H
