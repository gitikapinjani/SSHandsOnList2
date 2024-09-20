/*
============================================================================
Name : 11.c
Author : Gitika Pinjani
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void fun_reset(int sig_num) {

        struct sigaction seg;
    	
	seg.sa_handler=SIG_DFL;  
    	sigemptyset(&seg.sa_mask);
    	seg.sa_flags = 0;

    	sigaction(SIGINT,&seg,NULL);  

        raise(SIGINT);
}

int main() {

    	struct sigaction sig_ignore, sig_reset;

        sig_ignore.sa_handler = SIG_IGN; 
 
	sigemptyset(&sig_ignore.sa_mask);
    	sig_ignore.sa_flags = 0;

    	sigaction(SIGINT,&sig_ignore,NULL);  

    	printf("SIGINT is being ignored\n");
    	sleep(7);  

	sig_reset.sa_handler=fun_reset;  
    	sigemptyset(&sig_reset.sa_mask);
    	sig_reset.sa_flags = 0;

    	sigaction(SIGINT,&sig_reset,NULL); 

    	printf("SIGINT has been reset\n");

    
    	while(1){
        	pause();  
    	}

    	return 0;
}
/*
============================================================================
Output:
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 11.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
SIGINT is being ignored
SIGINT has been reset
^C
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 

============================================================================
*/
