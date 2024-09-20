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
