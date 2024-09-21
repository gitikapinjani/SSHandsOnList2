/*
============================================================================
Name : 33_server.c
Author : Gitika Pinjani
Description :Write a program to communicate between two machines using socket.
Date: 21st Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<sys/types.h>
int main(){
int sd,nsd,sz;
struct sockaddr_in serv, cli;
char buff[80];
sd = socket (AF_UNIX, SOCK_STREAM, 0);

serv.sin_family = AF_UNIX;
serv.sin_addr.s_addr = INADDR_ANY;
serv.sin_port = htons (5055);

bind (sd, (void*)(&serv), sizeof (serv));
listen (sd, 5);
sz=sizeof(cli);
nsd = accept (sd,(void*)( &cli), &sz);
read(nsd,buff,sizeof (buff));
printf("message from client:%s\n",buff);
write(nsd,"hi i am server\n",16);
}



/*
output: 

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./33serverOutput
message from client:hi i am client

*/
