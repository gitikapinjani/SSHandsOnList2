/*
============================================================================
Name : 7.c
Author : Gitika Pinjani
Description : 7. Write a simple program to print the created thread ids.
Date: 21th Sept, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myThread(void *arg)
{int num = *((int*)arg);
pthread_t thread_id = pthread_self();
printf("hello I am thread %lu.\n",arg);
return NULL;
}
int main()
{pthread_t thread[3];
int arg[3];

for(int i=0;i<3;i++)
{
arg[i] = i+1;
pthread_create(&thread[i],NULL,myThread, &arg[i]);
}

for(int i=0;i<3;i++)
{
pthread_join(thread[i] , NULL);
}
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
hello I am thread 140720738760308.
hello I am thread 140720738760312.
hello I am thread 140720738760316.

*/
