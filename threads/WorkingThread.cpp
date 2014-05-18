#include "WorkingThread.h"

WorkingThread::WorkingThread()
{
}

void WorkingThread::run()
{
    thread = new std::thread([&]()
    {
        while(true)
        {
            Action action = queue.pop(); // <- w tym miejscu sie zawiesi
            if(!action.isCancelled())
            {
                action.perform();
            }
        }
    });
}
