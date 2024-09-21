/*
============================================================================
Name : 21_1.c
Author : Gitika Pinjani
Description : 21. Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 21st Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    char buffer[100];

    mkfifo("myfifo21_1", 0666);
    mkfifo("myfifo21_2", 0666);

    int write_fd = open("myfifo21_1", O_WRONLY);
    int read_fd = open("myfifo21_2", O_RDONLY);

    while (1) {

        printf("Person 1: Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(write_fd, buffer, strlen(buffer) + 1);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        read(read_fd, buffer, sizeof(buffer)); 
        printf("Person 2 says: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    close(write_fd);
    close(read_fd);
    return 0;
}
