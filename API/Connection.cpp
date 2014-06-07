#include "Connection.h"

Connection::Connection(Socket socket)
{
	this->state = ConnectionState::CREATED;
}

AsyncOperation Connection::writeAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    WritingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    writing_thread.add(action);
    return AsyncOperation(action);
}

AsyncOperation Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    ReadingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    reading_thread.add(action);
    return AsyncOperation(action);
}

ConnectionState Connection::getState()
{
	return this->state;
}
