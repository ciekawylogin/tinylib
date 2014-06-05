#include "Connection.h"

Connection::Connection()
{

}

AsyncOperation Connection::writeAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    WritingAction action(data, dataSize, success, failure);
    writing_thread.add(action);
    return AsyncOperation(action);
}

AsyncOperation Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    ReadingAction action(data, dataSize, success, failure);
    reading_thread.add(action);
    return AsyncOperation(action);
}
