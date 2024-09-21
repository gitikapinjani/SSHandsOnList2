/*
============================================================================
Name : 24.c
Author : Gitika Pinjani
Description : Write a program to create a message queue and print the key and message queue id.
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){

	key_t key=ftok("file24",110);
	if(key==-1){
		perror("Error generating Key\n");
		return 1;
	}

	int msg_id=msgget(key,IPC_CREAT|0744);
	if(msg_id==-1){
                perror("Error generating Message Queue id\n");
                return 1;
        }

	
	printf("Message Queue is created\n");
	
	printf("Key:%d\n",key);
	printf("Message Queue id:%d\n",msg_id);

	return 0;

}

		
/*
output:
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 24.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
The Message Queue is created
Key:1845888638
Message Queue id:0
	
*/
