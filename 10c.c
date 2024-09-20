/*
============================================================================
Name : 10c.c
Author : Gitika Pinjani
Description : Write a separate program using sigaction system call to catch the following signals.
c. SIGFPE 
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sig_handler(int sig_num) {
        printf("Floating Point Exception caught\n");
        exit(1);
}

int main(){

        struct sigaction sig;
    
        memset(&sig,0,sizeof(sig));

        sig.sa_handler=sig_handler;

        sigaction(SIGFPE,&sig,NULL);

	int a=20;
	int b=0;
	int c=a/b;

        return 0;
}


/*
============================================================================
Output:
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 10c.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Floating Point Exception caught
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 

============================================================================
*/
