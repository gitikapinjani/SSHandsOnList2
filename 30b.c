/*
======================================================================================== 
Name: 30b.c
Author: Gitika Pinjani
Description: Write a program to create a shared memory.
b. attach with O_RDONLY and check whether you are able to overwrite.
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
msg =shmat(shmid,0,SHM_RDONLY);
printf("enter message:");
scanf("%[^\n]",msg);
printf("message from shared memory : %s\n", msg);
}
