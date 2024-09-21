/*
============================================================================
Name : 15.c
Author : Gitika Pinjani
Description : Write a simple program to send some data from parent to the child process.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char wMsg[] = "Hello gitika";
    char rMsg[100];

    pipe(fd);

    pid = fork();

    if (pid > 0) {
        close(fd[0]);
        write(fd[1], wMsg, strlen(wMsg) + 1);
        close(fd[1]);
    } else {
        close(fd[1]);
        read(fd[0], rMsg, sizeof(rMsg));
        printf("Child received: %s\n", rMsg);
        close(fd[0]);
    }

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Child received: Hello gitika

*/
