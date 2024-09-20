/*
======================================================================================== 
Name: 2.c
Author: Gitika Pinjani
Description: Write a program to print the system resource limits. Use getrlimit system call.
Date: 12th Sept, 2024
=========================================================================================
*/

#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct rlimit  old;
	if (getrlimit(RLIMIT_CPU, &old) == -1)
	       err(EXIT_FAILURE, "prlimit-1");
	printf("Previous limits: soft=%jd; hard=%jd\n",
           (intmax_t) old.rlim_cur, (intmax_t) old.rlim_max);
}


/*
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Previous limits: soft=-1; hard=-1
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 

*/
