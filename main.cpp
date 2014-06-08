#include <iostream>
#include <string>

#include "API/ServerConnection.h"
#include "API/ClientConnection.h"
#include "API/AsyncOperation.h"

#include "API/Server.h"
#include "API/Port.h"
#include "API/IP.h"

#include "API/events/DataWroteEvent.h"
#include "API/events/WritingErrorEvent.h"

#include "API/events/DataReadEvent.h"
#include "API/events/ReadingErrorEvent.h"

#include "API/EventListener.h"
#include "API/events/DataReadEvent.h"

#include "API/events/ClientConnectedEvent.h"

void wyslijDane(Connection conn)
{
    std::string str = "Hello, world!";
    conn.writeAsync((char *)str.c_str(), str.size(),
    [](Event *event) // success
    {
        std::cout << "Pomyslnie wyslano dane!" << std::endl;
    },
    [](Event *event) // error
    {
        std::cout << "Blad wysylania: "<< event->getMessage() << std::endl;
    });
}

void odbierzDane(Connection conn)
{
    const int max_length = 128;
    char buffer[max_length];
    conn.readAsync(buffer, max_length,
    [&buffer](Event *event) // success
    {
        std::cout << "Odebrano dane: " << buffer << std::endl;
    },
    [](Event *event) // error
    {
        std::cout << "Blad odbierania: "<< event->getMessage() << std::endl;
    });
}

int main()
{
    int m;
    std::cin >> m;

    if(m == 0)
    {
        Server s(1234);
        s.setConnectionListener([](Event *event_){
            ClientConnectedEvent *event = static_cast<ClientConnectedEvent *>(event_);
            std::cout << "polaczono" << std::endl;

            Connection *c = event->getConnection();
            std::cout << "wskaznik = " << c << "\n";
            char text[29];
            c->readSync(text, 28);
            std::cout << text << "\n";

            c->readSync(text, 28);
            std::cout << text << "\n";

            c->readSync(text, 28);
            std::cout << text << "\n";
        });
        s.listenSync();

        while(1){};
    }
    else
    {
        ClientConnection c;
        c.connect("127.0.0.1", 1234);

        while(1)
        {
            c.writeAsync("dupa", 4, [](Event *){}, [](Event *){});
        };
    }

/*
    int a;
    std::cin >> a;

    if(a == 0)
    {
        Socket socket;
        socket.setPort(1234);
        socket.bind();
        socket.listen();
        socket.accept([&socket](Event*){
            std::cout << "przyszlo polaczenie;" << std::endl;
            socket.write("dupa dupa gowno cycki", 21);
        });
    }
    else
    {
        Socket socket;
        socket.connect("127.0.0.1", 1234);
        char cos[50];
        socket.read(cos, 50);
        std::cout << cos;
        socket.write(cos, 21);
    }
*/
    
    return 0;
}

