#ifndef READINGTHREAD_H
#define READINGTHREAD_H

#include "WorkingThread.h"
#include <actions/ReadingAction.h>

typedef WorkingThread<ReadingAction> ReadingThread;

#endif // READINGTHREAD_H
