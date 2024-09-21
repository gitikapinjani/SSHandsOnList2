/*
============================================================================
Name :  20_1.c
Author : Gitika Pinjani
Description : 20. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21st Sept, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <unistd.h>
int main() {

char arr[80];
mkfifo("file20", 0666);
int fd = open("file20", O_WRONLY);
printf("%d\n", fd);
fgets(arr, 80,stdin);
printf("%s\n",arr); 
write(fd,arr,80);
close(fd);
return 0;
}
