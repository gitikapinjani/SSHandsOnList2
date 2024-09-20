/*
============================================================================
Name : 10a.c
Author : Gitika Pinjani
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


void sig_handler(int sig_num) {
	printf("Signal Segmentation Fault caught\n");
    	exit(1);
}

int main(){
	
	struct sigaction sig;
    
	memset(&sig,0,sizeof(sig));

    	sig.sa_handler=sig_handler;

	sigaction(SIGSEGV,&sig,NULL);

	int* p=NULL;
    	
	*p=10;

    	return 0;
}
/*
============================================================================
Output:
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 10a.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Signal Segmentation Fault caught
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 

============================================================================
*/
