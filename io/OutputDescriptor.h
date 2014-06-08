#ifndef OUTPUTDESCRIPTOR_H
#define OUTPUTDESCRIPTOR_H

#include "Descriptor.h"

/**
 * @brief Interface for OutputPipe or (Output)Socket
 */
class OutputDescriptor: public Descriptor
{
protected:
    OutputDescriptor();
public:
    virtual int write(const char *buffer, int buffer_size) const = 0;
};

#endif // OUTPUTDESCRIPTOR_H
