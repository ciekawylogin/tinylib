#include "Connection.h"

Connection::Connection()
{

}

AsyncOperation Connection::writeAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
	return AsyncOperation();
}

AsyncOperation Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
	return AsyncOperation();
    //ReadingAction reading_action(data, dataSize);
    //int reading_action_id = reading_thread.addAction(action);
}


