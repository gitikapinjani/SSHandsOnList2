/*
============================================================================
Name : 29.c
Author : Gitika Pinjani
Description : Write a program to remove the message queue.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){

        key_t key=ftok("file29",12);
        if(key==-1){
                perror("Error in generating the Key\n");
                return 1;
        }

        int msg_id=msgget(key,IPC_CREAT|0744);
        if(msg_id==-1){
                perror("Error in generating the Message Queue id\n");
                return 1;
        }

	if(msgctl(msg_id,IPC_RMID,NULL)==-1){
		perror("Error in removing the message queue\n");
		return 1;
	}

	printf("Message Queue is removed\n");

	return 0;

}


/*
Output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Message Queue is removed

*/
