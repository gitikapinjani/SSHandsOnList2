/*
======================================================================================== 
Name: 31b.c
Author: Gitika Pinjani
Description: Write a program to create a semaphore and initialize value to the semaphore.
b. create a counting semaphore
Date: 21st Sept, 2024
=========================================================================================
*/


#include<stdio.h>
#include<sys/sem.h>
#include<unistd.h>
union semun {
int val;
struct semid_ds *buff;
unsigned short int *array;
};

int main(void)
{union semun arg;
int key , semid;
key = ftok(".",'b');
semid=semget(key,1,IPC_CREAT |0644);
arg.val=2;
semctl(semid,0,SETVAL, arg);
getchar();
}
