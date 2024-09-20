/*
======================================================================================== 
Name: 6.c
Author: Gitika Pinjani
Description: Write a simple program to create three threads.
Date: 21st Sept, 2024
=========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* arg) {
int num = *((int*)arg);
printf("Thread number: %d\n", num);
pthread_exit(NULL);
}

int main() {
pthread_t thread[3];
int arg[3];  
int i;
for (i = 0; i < 3; i++) {
        arg[i] = i+1 ;
        pthread_create(&thread[i], NULL, func, &arg[i]);  
    }

   
    for (i = 0; i < 3; i++) {
        pthread_join(thread[i], NULL);
    }

    printf("Execution of all the threads are finished\n");

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Thread number: 1
Thread number: 2
Thread number: 3
Execution of all the threads are finished
*/
