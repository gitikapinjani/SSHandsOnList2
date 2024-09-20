/*
======================================================================================== 
Name: 3.c
Author: Gitika Pinjani
Description: Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 12th Sept, 2024
=========================================================================================
*/


#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

int main()
{
        struct rlimit  old;
        if (getrlimit(RLIMIT_CPU, &old) == -1)
               err(EXIT_FAILURE, "prlimit-1");
        printf("Previous limits: soft=%jd; hard=%jd\n",
           (intmax_t) old.rlim_cur, (intmax_t) old.rlim_max);

	old.rlim_cur = 16 * 1024 * 1024;
        old.rlim_max = 32 * 1024 * 1024;

	if(setrlimit(RLIMIT_CPU, &old) == -1)
               err(EXIT_FAILURE, "prlimit-2");
           printf("New limits: soft=%jd; hard=%jd\n",
                  (intmax_t) old.rlim_cur, (intmax_t) old.rlim_max);

}

/*
output: 

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 3.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Previous limits: soft=-1; hard=-1
New limits: soft=16777216; hard=33554432
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 

*/
