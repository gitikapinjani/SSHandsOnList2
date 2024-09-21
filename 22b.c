// Pipariya Darshitkumar
// MT2022035
/*
Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main()
{
    int f;
    mkfifo("file22", 0666);
    f = open("file22", O_WRONLY);

    if (f == -1)
    {
        perror("Error while opening FIFO file!");
        _exit(0);
    }
    char *st;
    long int size=100;
    printf("enter message\n");
    int l=getline(&st,&size,stdin);
    write(f, st, l);
    close(f);
}
