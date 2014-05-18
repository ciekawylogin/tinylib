#ifndef WORKINGTHREAD_H
#define WORKINGTHREAD_H

#include "BlockingQueue.h"
#include "../actions/Action.h"

/**
 * @brief Wątek przeznaczony do asynchronicznego wykonywania operacji konkretnego typu
 */
class WorkingThread
{
    std::thread *thread;
    BlockingQueue<Action&> queue;
public:
    WorkingThread();
    void run();

    virtual void performAction() = 0;
};

#endif // WORKINGTHREAD_H
