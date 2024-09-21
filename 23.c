/*
============================================================================
Name : 23.c
Author : Gitika Pinjani
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 21st Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdio.h>

void main()
{
    long maxFiles;  
    long sizeOfPipe;

    char *s = "myfifo23";
    mkfifo(s, S_IRWXU);

    maxFiles = sysconf(_SC_OPEN_MAX);

    printf("Maximum number of files that can be opened is: %ld\n", maxFiles);


    printf("Maximum size of pipe: %d\n", PIPE_BUF);
    
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Maximum number of files that can be opened is: 1024
Maximum size of pipe: 4096

*/
