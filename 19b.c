#include <stdio.h>
#include <stdlib.h>

int main() {

    int s = system("mkfifo myfifo_b");

    if (s == -1) {
        perror("mkfifo command failed");
        return 1;
    }

    printf("FIFO file created using mkfifo command.\n");
    return 0;
}
