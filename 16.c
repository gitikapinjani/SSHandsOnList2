/*
============================================================================
Name : 16.c
Author : Gitika Pinjani
Description :Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipe1[2];
    int pipe2[2];
    pid_t pid;
    char pMsg[] = "Message from parent!";
    char cMsg[] = "Message from child!";
    char rMsg[100];

    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if (pid > 0) {
        close(pipe1[0]);
        close(pipe2[1]);

        write(pipe1[1], pMsg, strlen(pMsg) + 1);
	
	close(pipe1[1]);
        read(pipe2[0], rMsg, sizeof(rMsg));
        printf("Parent received: %s\n", rMsg);
        close(pipe2[0]);

    } else {
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], rMsg, sizeof(rMsg));
        printf("Child received: %s\n", rMsg);
	close(pipe1[0]);
        write(pipe2[1], cMsg, strlen(cMsg) + 1);
        close(pipe2[1]);
    }

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Child received: Message from parent!
Parent received: Message from child!

*/
