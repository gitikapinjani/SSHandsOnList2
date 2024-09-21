/*
======================================================================================== 
Name: 19a.c
Author: Gitika Pinjani
Description: Create a FIFO file by
a. mknod command
Date: 21st Sept, 2024
=========================================================================================
*/
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

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
FIFO file is created using mknod command.

*/
