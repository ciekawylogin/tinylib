#include <iostream>
#include <string>

#include <unistd.h>

#include "API/ServerConnection.h"
#include "API/ClientConnection.h"
#include "API/AsyncOperation.h"

#include "API/Server.h"
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

int main()
{
    std::cout << "Wybierz tryb dzialania programu (0 = serwer, 1 = klient):" << "\n";
    int a;
    std::cin >> a;
    char tab[50];
    if(a == 0)
    {
        Server server(1251);
        server.setSecurityPolicy(ACCEPT_ONLY_LISTED);
        /*
         * uproszczona wersja:

        const char tab[50] = "wiadomosc";
        Server server(1243);
        server.listenForOneClient()->writeSync(tab, 40);
         */

        server.setConnectionListener([&tab](PEvent event_)
        {
            std::shared_ptr<ClientConnectedEvent> event = std::dynamic_pointer_cast<ClientConnectedEvent>(event_);
            std::cout << "Podlaczyl sie klient" << "\n";
            std::shared_ptr<Connection> connection = event->getConnection();
            for(int i=0;i<10;++i)
            {
                connection->readAsync(tab, 50, [&tab](PEvent event)
                { // success
                    std::cout << "odebrano dane" << "\n";
                    std::cout << tab << "\n";
                },  [](PEvent event)
                { // failure
                    std::cout << "blad: " << event->getMessage() << "\n";
                });
                std::cout << "zawolalem readAsync() \n";
            }
            int i=0;
            while(1)
            {
                std::cout << "Dzialam w glownym watku " << i++ << "\n";
                sleep(1);
            }
        });
        server.listenAsync();
        int i=0;
        while(1)
        {
            sleep(1);
        }
    }
    else if(a == 1)
    {
        ClientConnection client;
        client.connect("192.168.1.23", 1251);
        for(int i=0;;++i)
        {
            std::string str;
            std::cin >> str;
            client.writeSync(str.c_str(), str.length());
        }
    }
    else
    {
        std::cout << "nierozpoznane polecenie " << "\n";
    }
    return 0;
}
