#ifndef LISTENERCALLTHREAD_H
#define LISTENERCALLTHREAD_H

#include "actions/WritingAction.h"
#include "WorkingThread.h"

typedef WorkingThread<WritingAction> ListenerCallThread;

#endif // LISTENERCALLTHREAD_H
