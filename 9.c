/*
============================================================================
Name : 9.c
Author : Gitika Pinjani
Description : 9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signalint_handler(int sig){
printf("received SIGINT but this signal handler function will not be called because of SIG_IGN\n");
}

int main()
{

signal(SIGINT,SIG_IGN);
printf("SIGINT is ignored\n");

sleep(5);

signal(SIGINT,SIG_DFL);
printf("SIGINT is reset to it's default action\n");

sleep(5);

printf("program exited");
 
return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
SIGINT is ignored
SIGINT is reset to it's default action
program exited

*/
