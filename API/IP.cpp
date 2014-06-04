#include "IP.h"
#include <stdexcept>

IP::IP(std::string IP_str)
{
    size_t index = 0;
    for(auto c: IP_str)
    {
        if(isdigit(c))
        {
            address[index] *= 10;
            address[index] += c - '0';
        }
        else
        {
            index++;
        }
    }
}

IP::IP(int)
{
    throw new std::runtime_error("not yet implemented");
}
