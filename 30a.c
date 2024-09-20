/*
======================================================================================== 
Name: 30a.c
Author: Gitika Pinjani
Description: Write a program to create a shared memory.
a. write some data to the shared memory
Date: 21st Sept, 2024
=========================================================================================
*/


#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main(void){
int key,shmid;
char *data;
key = ftok(".",'c');
shmid=shmget(key,1024,IPC_CREAT|0744);
data =shmat(shmid,0,0);
printf("enter message:");
scanf("%[^\n]",data);
printf("message from shared memory : %s\n", data);
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
enter message:hello, gitika
message from shared memory : hello, gitika

*/
