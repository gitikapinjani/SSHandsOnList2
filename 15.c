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
