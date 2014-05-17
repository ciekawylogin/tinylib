#ifndef READINGTHREAD_H
#define READINGTHREAD_H

#include "WorkingThread.h"

class ReadingThread: public WorkingThread
{
public:
    ReadingThread();
    int addOperation();
};

#endif // READINGTHREAD_H
