/*
============================================================================
Name :  20_2.c
Author : Gitika Pinjani
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char buffer[100];
    int fifo_fd = open("file20", O_RDONLY);
    if (fifo_fd == -1) {
        perror("open for read failed");
        return 1;
    }

    read(fifo_fd, buffer, sizeof(buffer));
            printf("Received message: %s", buffer);

    close(fifo_fd);
    return 0;
}
