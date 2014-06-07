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
    std::shared_ptr<BlockingQueue<T> > queue;
public:
    WorkingThread():
        queue(new BlockingQueue<T>())
    {

    }

    void run()
    {
        thread = new std::thread([&]()
        {
            while(true)
            {
                Action action = queue.pop(); // <- w tym miejscu sie zawiesi
                if(!action.isCancelled())
                {
                    action.perform();
                    std::cout << "action performed" << std::endl;
                }
                else
                {
                    std::cout << "action cancelled" << std::endl;
                }
            }
        });

        // przerwano

        std::cerr << "Przerwano wykonanie watku" << std::endl;
    }

    void add(T action)
    {
        queue->push(action);
    }
};

#endif // WORKINGTHREAD_H
