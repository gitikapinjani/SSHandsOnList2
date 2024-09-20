/*
======================================================================================== 
Name: 30c.c
Author: Gitika Pinjani
Description: Write a program to create a shared memory.
c. detach the shared memory
Date: 21st Sept, 2024
=========================================================================================
*/


#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
int main(void){
int key,shmid;
char *msg;
key = ftok(".",'c');
shmid=shmget(key,1024,IPC_CREAT|0744);
msg =shmat(shmid,0,0);
printf("shared memory attached\n");
printf("press enter to detach shared memory\n");
getchar();
shmdt(msg);
printf("pointer detach from shared memory\n");
}
