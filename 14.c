/*
============================================================================
Name : 14.c
Author : Gitika Pinjani
Description : 14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char wMsg[] = "Hello gitika";
    char rMsg[100];

    pipe(fd);

    write(fd[1], wMsg, strlen(wMsg) + 1);

    read(fd[0], rMsg, sizeof(rMsg));

    printf("Read from pipe: %s\n", rMsg);

    close(fd[0]);
    close(fd[1]);

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Read from pipe: Hello gitika

*/
