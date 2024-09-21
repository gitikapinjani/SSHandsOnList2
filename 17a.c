/*
======================================================================================== 
Name: 17a.c
Author: Gitika Pinjani
Description: Write a program to execute ls -l | wc.
a. use dup
Date: 21st Sept, 2024
=========================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2]; 
    pid_t pid1, pid2;

    pipe(fd);
    pid1 = fork();

    if (pid1 == 0) {
        close(STDOUT_FILENO);

        if (dup(fd[1]) == -1) {
            perror("dup");
            exit(EXIT_FAILURE);
        }
        close(fd[0]);
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);
    
    }

    
    pid2 = fork();
   

    if (pid2 == 0) {
        close(STDIN_FILENO);
        if (dup(fd[0]) == -1) {
            perror("dup");
            exit(EXIT_FAILURE);
        }
close(fd[0]);
        close(fd[1]);
        execlp("wc", "wc", NULL);

    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
     78     690    5139
*/
