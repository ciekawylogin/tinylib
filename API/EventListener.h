#ifndef EVENTLISTENER_H
#define EVENTLISTENER_H

#include "events/Event.h"
#include "events/ClientConnectedEvent.h"

#include <functional>

typedef std::function<void(Event)> EventListener;

//--------------------------------------------------------------------------------
//spokojnie. dodane tylko to co nizej, latwo usunac
// to tak bardziej zebym nie zapomnial co chcialem pytac
// dopoki sie nie spotkamy to tego nie zrobimy

EventListener acceptConnection = [](ClientConnectedEvent conn)->void{

    //pipe w obrebie jednego programu, jak zrobic w roznych???

    int pfd[2];
    pid_t cpid;
    char buf;

    if (pipe(pfd) == -1) { perror("pipe"); exit(EXIT_FAILURE); }
    cpid = fork();
    if (cpid == -1) { perror("fork"); exit(EXIT_FAILURE); }
    if (cpid == 0) {    /* Child reads from pipe */
        close(pfd[1]);          /* Close unused write end */
        close(conn.newSocket);
        while (read(pfd[0], &buf, 1) > 0);
        close(pfd[0]);
        _exit(EXIT_SUCCESS);
    } else {            /* Parent writes argv[1] to pipe */
        close(pfd[0]);          /* Close unused read end */
        close(conn.oldSocket);
        write(pfd[1], "cos????", -1);
        close(pfd[1]);          /* Reader will see EOF */
        wait(NULL);             /* Wait for child */
        exit(EXIT_SUCCESS);
       }
};

#endif // EVENTLISTENER_H
