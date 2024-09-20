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
