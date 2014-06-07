#ifndef WRITINGACTION_H
#define WRITINGACTION_H

#include "Action.h"
#include "../API/EventListener.h"

class WritingAction : public Action
{
public:
    WritingAction(char *data, int dataSize, EventListener success, EventListener failure);

    void perform();
};

#endif // WRITINGACTION_H
