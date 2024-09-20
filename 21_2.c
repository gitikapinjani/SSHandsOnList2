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

    int read_fd = open("myfifo21_1", O_RDONLY);
    int write_fd = open("myfifo21_1", O_WRONLY);

    while (1) {
        read(read_fd, buffer, sizeof(buffer));
        printf("Person 1 says: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

        printf("Person 2: Enter a message: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(write_fd, buffer, strlen(buffer) + 1);

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
    }

    close(write_fd);
    close(read_fd);
    return 0;
}
