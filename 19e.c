#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {

      if (mkfifo("myfifo_e", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }

    printf("FIFO file created using mkfifo library function.\n");
    return 0;
}
