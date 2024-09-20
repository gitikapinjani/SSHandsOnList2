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
