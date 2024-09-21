/*
============================================================================
Name : 22.c
Author : Gitika Pinjani
Description :Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21st Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int main() {
    int fifo_fd;
    char buffer[1024];
    fd_set read_fds;
    struct timeval timeout;
    int ret;

    mkfifo("myfifo222", 0666);
    fifo_fd = open("myfifo222", O_RDONLY | O_NONBLOCK);

    FD_ZERO(&read_fds);
    FD_SET(fifo_fd, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    ret = select(fifo_fd + 1, &read_fds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
        close(fifo_fd);
        exit(EXIT_FAILURE);
    } else if (ret == 0) {
        printf("Timeout occurred! No data within %d seconds.\n", 10);
    } else {
        if (FD_ISSET(fifo_fd, &read_fds)) {
            ssize_t num_bytes = read(fifo_fd, buffer, sizeof(buffer) - 1);
            if (num_bytes > 0) {
                buffer[num_bytes] = '\0'; 
                printf("Data read from FIFO: %s\n", buffer);
            } else {
                printf("No data read or end of file reached.\n");
            }
        }
    }

    close("myfifo222");

    return 0;
}

/*
output:
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Data read from FIFO: hello from fifo file


gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ echo "hello from fifo file" >> myfifo222

*/
