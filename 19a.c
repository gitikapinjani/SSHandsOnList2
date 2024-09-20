#include <stdio.h>
#include <stdlib.h>

int main() {

    int s = system("mknod myfifo_a p");
    if (s == -1) {
        perror("mknod failed");
        return 1;
    }

    printf("FIFO file is created using mknod command.\n");
    return 0;
}
