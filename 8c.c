/*
============================================================================
Name : 8c.c
Author : Gitika Pinjani
Description : 8. Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void  handle_signal()
{
printf("caught SIGFPE signal\n");
exit(0);
}

void main()
{

__sighandler_t stat;
stat = signal(SIGFPE , (void*)handle_signal);

raise(SIGFPE);

}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
caught SIGFPE signal

*/
