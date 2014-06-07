#ifndef READINGACTION_H
#define READINGACTION_H

#include "Action.h"
#include "../API/EventListener.h"

class ReadingAction : public Action
{
public:
    ReadingAction(char *data, int dataSize, EventListener success, EventListener failure);

    void perform();
};

#endif // READINGACTION_H
