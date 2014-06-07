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




/*
void wyslijDane(Connection conn)
{
    std::string str = "Hello, world!";
    conn.writeAsync((char *)str.c_str(), str.size(),
    [](Event event) // success
    {
        std::cout << "Pomyslnie wyslano dane!" << std::endl;
    },
    [](Event event) // error
    {
        std::cout << "Blad wysylania: "<< event.getMessage() << std::endl;
    });
}

void odbierzDane(Connection conn)
{
    const int max_length = 128;
    char buffer[max_length];
    conn.readAsync(buffer, max_length,
    [&buffer](Event event) // success
    {
        std::cout << "Odebrano dane: " << buffer << std::endl;
    },
    [](Event event) // error
    {
        std::cout << "Blad odbierania: "<< event.getMessage() << std::endl;
    });
}
*/

int main()
{
    using namespace std;
//    int a;
//    std::cin >> a;

//    if(a == 0)
//    {
//        Socket socket;
//        socket.setPort(1235);
//        socket.bind();
//        socket.listen();
//        socket.accept([&socket](Event*){
//            std::cout << "przyszlo polaczenie;" << std::endl;
//            socket.write("dupa dupa gowno cycki", 21);
//        });
//    }
//    else
//    {
//        Socket socket;
//        socket.connect("192.168.1.23", 1235);
//        char cos[50];
//        socket.read(cos, 50);
//        std::cout << cos;
//        socket.write(cos, 21);
//    }






    return 0;
}

