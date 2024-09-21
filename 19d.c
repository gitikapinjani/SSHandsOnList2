/*
======================================================================================== 
Name: 19d.c
Author: Gitika Pinjani
Description: Create a FIFO file by
d. mknod system call
Date: 21st Sept, 2024
=========================================================================================
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {

    if (mknod("myfifo_d", S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }

    printf("FIFO file created using mknod system call.\n");
    return 0;
}
