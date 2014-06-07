#ifndef LISTENERCALLTHREAD_H
#define LISTENERCALLTHREAD_H

#include "WorkingThread.h"
#include "../actions/ListenerCallAction.h"

typedef WorkingThread<ListenerCallAction> ListenerCallThread;

#endif // LISTENERCALLTHREAD_H
