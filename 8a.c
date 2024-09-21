/*
============================================================================
Name : 8a.c
Author : Gitika Pinjani
Description : 8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 21th Sept, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handle_signal(int sig)
{
printf("caught SIGSEGV signal\n");
exit(1);

}



void main()
{
__sighandler_t stat;

stat= signal( SIGSEGV, (void*)handle_signal);

if( stat == SIG_ERR){
printf("error\n");
}

else{
raise(SIGSEGV);
}
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
caught SIGSEGV signal

*/
