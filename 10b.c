/*
============================================================================
Name : 10b.c
Author : Gitika Pinjani
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT 
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sig_handler(int sig_num) {
	printf("Signal SIGINT Caught\n");
    	exit(1);
}

int main(){
	
	struct sigaction sig;
    
	memset(&sig,0,sizeof(sig));

    	sig.sa_handler=sig_handler;

	sigaction(SIGINT,&sig,NULL);

	while(1);
    	
  	return 0;
}


/*
============================================================================
Output:
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 10b.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
^CSignal SIGINT Caught
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$
============================================================================
*/
