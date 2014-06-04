#include "Connection.h"

Connection::Connection()
{

}

AsyncOperation Connection::writeAsync(char *data, int dataSize, EventListener success, EventListener failure)
{

}

AsyncOperation Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    //ReadingAction reading_action(data, dataSize);
    //int reading_action_id = reading_thread.addAction(action);
}


