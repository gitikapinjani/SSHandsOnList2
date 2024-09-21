
/*
============================================================================
Name : 8d.c
Author : Gitika Pinjani
Description : 8. Write a separate program using signal system call to catch the following signals.
d. SIGALRM (use alarm system call)
Date: 21st Sept, 2024.
============================================================================
*/


#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void sig_alrm()
{
printf("caught signal alarm\n");
}

void main()
{

__sighandler_t status;
status = signal(SIGALRM , (void*)sig_alrm);

if(status == SIG_ERR){
printf("error in assigning signal handler\n");
}

else{
raise(SIGALRM);
}
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
caught signal alarm

*/
