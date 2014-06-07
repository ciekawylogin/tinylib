#include "Connection.h"

Connection::Connection(Socket socket)
{
    writing_thread.run();
    reading_thread.run();
    listener_call_thread.run();
    state = ConnectionState::CREATED;
}

AsyncOperation Connection::writeAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    WritingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    writing_thread.add(action);
	this->state = ConnectionState::SENDING;
    return AsyncOperation(action);
}

AsyncOperation Connection::readAsync(char *data, int dataSize, EventListener success, EventListener failure)
{
    ReadingAction action(socket, data, dataSize, success, failure, listener_call_thread);
    reading_thread.add(action);
	this->state = ConnectionState::RECEIVING;
    return AsyncOperation(action);
}
<<<<<<< HEAD

void Connection::writeSync(const char *data, int dataSize)
{
	this->state = ConnectionState::SENDING;
}

void Connection::readSync(char *data, int maxDataSize)
{
	this->state = ConnectionState::RECEIVING;
}

ConnectionState Connection::getState()
{
	return this->state;
}
=======
>>>>>>> ea5caaf1cf1bfdf48b0ac3d8b47675e48faadbe9
