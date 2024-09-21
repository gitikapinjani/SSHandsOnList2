/*
======================================================================================== 
Name: 19a.c
Author: Gitika Pinjani
Description: Create a FIFO file by
b. mkfifo command
Date: 21st Sept, 2024
=========================================================================================
*/

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
