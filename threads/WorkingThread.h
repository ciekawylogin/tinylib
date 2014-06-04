#ifndef WORKINGTHREAD_H
#define WORKINGTHREAD_H

#include <memory>
#include <iostream>

#include "BlockingQueue.h"
#include "../actions/Action.h"

/**
 * @brief Wątek przeznaczony do asynchronicznego wykonywania operacji konkretnego typu
 */
template <typename T>
class WorkingThread
{
protected:
    std::thread *thread;
    BlockingQueue<T> queue;
public:
    WorkingThread()
    {

    }

    void run()
    {
        thread = new std::thread([&]()
        {
            while(true)
            {
                PAction action = queue.pop(); // <- w tym miejscu sie zawiesi
                if(!action->isCancelled())
                {
                    action->perform();
                }
            }
        });

        // przerwano

        std::cerr << "Przerwano wykonanie watku" << std::endl;
    }
};

#endif // WORKINGTHREAD_H
