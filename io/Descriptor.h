#ifndef DESCRIPTOR_H
#define DESCRIPTOR_H

class Descriptor
{
public:
    Descriptor();
    virtual int getUnixDescriptor() const = 0;
};

#endif // DESCRIPTOR_H
