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
#include "pipes/OutputPipe.h"
#include "pipes/InputPipe.h"

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

int main() //try
{
   /* int m;
    std::cin >> m;

    std::pair<InputPipe, OutputPipe> pipes = Pipe::createPipesPair();

    std::thread thread_1([pipes](){
        char buf[20];
        pipes.first.read(buf, 20);
        std::cout << buf << "\n";
    });

    std::thread thread_2([pipes](){
        char buf[20] = "bijcie masterczulki";
        pipes.second.write(buf, 20);
    });

    thread_1.join();
    thread_2.join();
*/

    int i =10;
    int a;
    while(i--){
    std::cin >> a;

    if(a == 0)
    {
        Socket socket;
        socket.setPort(1134+i);
        socket.bind();
        socket.listen();
        socket.accept([&socket](Event*){
            std::cout << "przyszlo polaczenie;" << std::endl;
            socket.write("dupa dupa gowno cycki", 21);
            char buf[50];
            socket.read(buf,50);
            std::cout<<buf<<"\n";
         });
    }
    else
    {
        Socket socket;
        //socket.connect("127.0.0.1", 1234);
        socket.connect("127.0.0.1", 1134+i);
        char cos[50];
        socket.read(cos, 50);
        std::cout<<cos<<"\n";
        socket.write(cos, 21);
    }

    }
    return 0;
}
//catch (std::exception e)
//{
 //   std::cout << e.what() << std::endl;
//}
