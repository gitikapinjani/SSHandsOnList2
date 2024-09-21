/*
============================================================================
Name : 34b_client.c
Author : Gitika Pinjani
Description :Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 21th Sep, 2024.
============================================================================
*/


#include<stdio.h>
#include <errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
int main()
{struct sockaddr_in serv;
int sd;
char buff[80];
sd = socket (AF_UNIX, SOCK_STREAM, 0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons (5001);
connect (sd,(void*)( &serv),sizeof (serv));
int n = write(sd,"hi i am client\n",16);
printf("%d",n);
if (n < 0) {
 perror("ERROR writing to socket");}        
printf("hello error");
read(sd,buff,sizeof (buff));
printf("message from server %s\n",buff);
}
