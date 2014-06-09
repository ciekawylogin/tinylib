SOURCES += \
    main.cpp \
    API/Connection.cpp \
    API/ClientConnection.cpp \
    API/ServerConnection.cpp \
    API/Server.cpp \
    API/AsyncOperation.cpp \
    API/IP.cpp \
    API/events/Event.cpp \
    API/events/SuccessEvent.cpp \
    API/events/DataWroteEvent.cpp \
    API/events/FailureEvent.cpp \
    API/events/WritingErrorEvent.cpp \
    API/events/ReadingErrorEvent.cpp \
    API/events/DataReadEvent.cpp \
    API/events/ClientConnectedEvent.cpp \
    API/events/ConnectedToServerEvent.cpp \
    API/events/ClientDeniedEvent.cpp \
    API/IPRange.cpp \
    sockets/Socket.cpp \
    threads/WritingThread.cpp \
    threads/ReadingThread.cpp \
    threads/WorkingThread.cpp \
    actions/Action.cpp \
    actions/WritingAction.cpp \
    actions/ReadingAction.cpp \
    actions/ListenerCallAction.cpp \
    threads/ListenerCallThread.cpp \
    pipes/Pipe.cpp \
    encrypt/Encrypt.cpp \
    pipes/InputPipe.cpp \
    pipes/OutputPipe.cpp \
    io/Select.cpp \
    io/InputDescriptor.cpp \
    io/OutputDescriptor.cpp \
    io/Descriptor.cpp

OTHER_FILES += \
    README.md

HEADERS += \
    API/Connection.h \
    API/ClientConnection.h \
    API/ServerConnection.h \
    API/Server.h \
    API/AsyncOperation.h \
    API/IP.h \
    API/events/Event.h \
    API/events/SuccessEvent.h \
    API/events/DataWroteEvent.h \
    API/events/FailureEvent.h \
    API/events/WritingErrorEvent.h \
    API/events/ReadingErrorEvent.h \
    API/events/DataReadEvent.h \
    API/events/ClientConnectedEvent.h \
    API/events/ConnectedToServerEvent.h \
    API/events/ClientDeniedEvent.h \
    API/EventListener.h \
    API/IPRange.h \
    sockets/Socket.h \
    threads/BlockingQueue.h \
    threads/WritingThread.h \
    threads/ReadingThread.h \
    threads/WorkingThread.h \
    actions/Action.h \
    actions/WritingAction.h \
    actions/ReadingAction.h \
    actions/ListenerCallAction.h \
    threads/ListenerCallThread.h \
    pipes/Pipe.h \
    API/ConnectionState.h \
    encrypt/Encrypt.h \
    pipes/InputPipe.h \
    pipes/OutputPipe.h \
    io/Select.h \
    io/InputDescriptor.h \
    io/OutputDescriptor.h \
    io/Descriptor.h \
    API/SecurityPolicy.h

CONFIG += c++11
