#include "Connection.h"

Connection::Connection(Socket socket)
{
<<<<<<< HEAD
<<<<<<< HEAD
	this->state = ConnectionState::CREATED;
=======

>>>>>>> 54657ccd51bc46f5e16d6f334afaa3ecd8c505c0
=======

>>>>>>> d39d4605f0a837c1ac48039866ebedfaf6a3977a
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
