/*
============================================================================
Name : 26.c
Author : Bhavya Joshi
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 20th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

struct mg_info{
	long msg_type;
	char msg_text[50];
}my_msg;

int main(){

        key_t key=ftok("file26",12);
        if(key==-1){
                perror("Error generating Key\n");
                return 1;
        }

        int msg_id=msgget(key,IPC_CREAT|0744);
        if(msg_id==-1){
                perror("Error generating Message Queue id\n");
                return 1;
        }

	my_msg.msg_type=1;

	printf("Enter message that you want to send through Message Queue\n");
	fgets(my_msg.msg_text,sizeof(my_msg.msg_text), stdin);

	if((msgsnd(msg_id,&my_msg,sizeof(my_msg.msg_text),0))==-1){
		perror("Error  sending message\n");
		return 1;
	}

        return 0;

}

/*
Output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Enter message that you want to send through Message Queue
hello gitika
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x6e06067e 0          gitikapinj 744        0            0           
0x0c060bd8 1          gitikapinj 744        0            0           
0x0c060c78 2          gitikapinj 744        50           1 

*/
