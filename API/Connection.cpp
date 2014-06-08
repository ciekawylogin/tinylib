#include "Connection.h"

Connection::Connection(PConnect socket):
    socket(socket)
{
    writing_thread.run();
    reading_thread.run();
    listener_call_thread.run();
    state = ConnectionState::CREATED;
}

AsyncOperation* Connection::writeAsync(const char *data, int dataSize, EventListener success, EventListener failure)
{
    WritingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    writing_thread.add(action);
    this->state = ConnectionState::ASYNC_SENDING;
    return new AsyncOperation(action);
}

AsyncOperation* Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    ReadingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    reading_thread.add(action);
    this->state = ConnectionState::ASYNC_RECEIVING;
    return new AsyncOperation(action);
}

void Connection::writeSync(const char *data, int dataSize)
{
    socket->write(data, dataSize);
	this->state = ConnectionState::SYNC_SENDING;
}

void Connection::readSync(char *data, int maxDataSize)
{
    socket->read(data, maxDataSize);
	this->state = ConnectionState::SYNC_RECEIVING;
}

ConnectionState Connection::getState()
{
	return this->state;
}
