/*
============================================================================
Name : 8f.c
Author : Gitika Pinjani
Description : 8. Write a separate program using signal system call to catch the following signals.
f. SIGVTALRM (use setitimer system call)
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void handle_sigvtalrm()
{
    printf("SIGVTALRM caught\n");
    _exit(0);
}

void main()
{
    __sighandler_t status;
    struct itimerval timer;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    int timerStatus = setitimer(ITIMER_VIRTUAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");
    status = signal(SIGVTALRM, (void *)handle_sigvtalrm);
    if (status == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        while (1)
            ;
    }
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
SIGVTALRM caught

*/
