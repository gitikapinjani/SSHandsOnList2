/*
============================================================================
Name : 33_server.c
Author : Gitika Pinjani
Description :Write a program to communicate between two machines using socket.
Date: 21th Sep, 2024.
============================================================================
*/

#include<stdio.h>
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
serv.sin_port = htons (5055);
connect (sd,(void*)( &serv),sizeof (serv));
write(sd,"hi i am client\n",16);
read(sd,buff,sizeof (buff));
printf("message from server %s\n",buff);
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
message from server hi i am server

*/
