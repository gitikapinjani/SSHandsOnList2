/*
======================================================================================== 
Name: 4.c
Author: Gitika Pinjani
Description: Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 12th Sept, 2024
=========================================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
	unsigned long long dst;
	__asm__ __volatile__("rdtsc":"=A" (dst));
}

int main()
{
	int i, nano;
	unsigned long long int start, end;
	start = rdtsc();
	for(i=0;i<=100;i++)
		getpid();
	end = rdtsc();
	nano = (end - start)/2.4;
	printf("Time taken by getpid() = %d nano sec. \n",nano);
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 4.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Time taken by getpid() = 27336 nano sec. 
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 

*/
