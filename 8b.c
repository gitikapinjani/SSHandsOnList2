/*
============================================================================
Name : 8b.c
Author : Gitika Pinjani
Description : 8. Write a separate program using signal system call to catch the following signals.
b. SIGINT
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void handle_signal() 
{
printf("caught SIGINT signal\n" );
exit(0);
}


void  main()
{

__sighandler_t stat;

stat =  signal(SIGINT , (void*)handle_signal);
raise(SIGINT);


}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
caught SIGINT signal

*/
