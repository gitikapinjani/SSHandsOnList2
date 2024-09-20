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
