/*
============================================================================
Name : 12.c
Author : Gitika Pinjani
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

int main(){
    
	pid_t p_id = fork();  

    	if(p_id==0){
        
		printf("PID of child process: %d.\n",getpid());
        	printf("PID of parent process:  %d.\n",getppid());
        	
		printf("Sending SIGKILL signal to Parent Process.\n");
		kill(getppid(),SIGKILL);

		sleep(7);

        	printf("Child process with PID %d is now Orphan.\n",getpid());
		printf("New Parent PID id %d.\n",getppid());
           
    	}

	else{
     
        	printf("Parent Process with PID %d is alive.\n",getpid());
		printf("Parent Process is waiting for signal from Child Process.\n");
        	
		sleep(15); 
    	}

    	return 0;
}

/*
============================================================================

Output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 12.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Parent Process with PID 5304 is alive.
Parent Process is waiting for signal from Child Process.
PID of child process: 5305.
PID of parent process:  5304.
Sending SIGKILL signal to Parent Process.
Killed
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ Child process with PID 5305 is now Orphan.
New Parent PID id 1731.

============================================================================
*/
