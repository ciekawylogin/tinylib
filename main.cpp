#include <iostream>
#include <string>

#include <unistd.h>

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
#include "pipes/OutputPipe.h"
#include "pipes/InputPipe.h"

void wyslijDane(Connection conn)
{
    std::string str = "Hello, world!";
    conn.writeAsync((char *)str.c_str(), str.size(),
    [](PEvent event) // success
    {
        std::cout << "Pomyslnie wyslano dane!" << std::endl;
    },
    [](PEvent event) // error
    {
        std::cout << "Blad wysylania: "<< event->getMessage() << std::endl;
    });
}

void odbierzDane(Connection conn)
{
    const int max_length = 128;
    char buffer[max_length];
    conn.readAsync(buffer, max_length,
    [&buffer](PEvent event) // success
    {
        std::cout << "Odebrano dane: " << buffer << std::endl;
    },
    [](PEvent event) // error
    {
        std::cout << "Blad odbierania: "<< event->getMessage() << std::endl;
    });
}

int main() //try
{
    std::cout << "Wybierz tryb dzialania programu (0 = serwer, 1 = klient):" << "\n";
    int a;
    std::cin >> a;
    if(a == 0)
    {
        Server server(1239);
        server.setConnectionListener([](PEvent event_)
        {
            std::shared_ptr<ClientConnectedEvent> event = std::dynamic_pointer_cast<ClientConnectedEvent>(event_);
            std::cout << "Podlaczyl sie klient" << "\n";
            std::shared_ptr<Connection> connection = event->getConnection();
            for(int i=0;i<10;++i)
            {
                char tab[50];
                connection->readAsync(tab, 50, [tab](PEvent event)
                { // success
                    std::cout << "odebrano dane" << "\n";
                }, [](PEvent event)
                { // failure
                    std::cout << "blad: " << event->getMessage() << "\n";
                });
                std::cout << "zawolalem readAsync(), stan = " << connection->getState()  << "\n";
            }
        });
        server.listenAsync();
        int i=0;
        while(1)
        {
            std::cout << "Dzialam w glownym watku " << i++ << "\n";
            sleep(1);
        }
    }
    else if(a == 1)
    {

        ClientConnection client;
        client.connect("192.168.1.23", 1241);
        std::cout << "polaczono z klientem, kliknij enter aby wyslac wiadomosc" << "\n";
        while(1)
        {
            std::string str;
            std::cin >> str;
            client.writeSync("Hello, world!", 13);
        }
    }
    else
    {
        std::cout << "nierozpoznane polecenie " << "\n";
    }
    return 0;
}
//catch (std::exception e)
//{
 //   std::cout << e.what() << std::endl;
//}
