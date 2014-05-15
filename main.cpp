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

void wyslijDane(std::string str, Connection conn)
{
    conn.writeAsync(str.c_str(), str.size(),
    [](Event event) // success
    {
        std::cout << "Pomyslnie wyslano dane!" << std::endl;
    },
    [](Event event) // error
    {
        std::cout << "Blad wysylania: "<< event.getMessage() << std::endl;
    });
}

int main()
{
    std::cout << "Hello world\n";
    return 0;
}
