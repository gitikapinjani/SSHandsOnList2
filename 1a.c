/*
======================================================================================== 
Name: 1a.c
Author: Gitika Pinjani
Description: Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
Date: 3rd Sept, 2024
=========================================================================================
*/

#include<sys/time.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/time.h>
void handleSignal(int sig) {
    printf("Timer expired in 10 seconds and 10 microsecond interval and signal number is %d\n",sig);
}

int main(){
signal(SIGALRM, handleSignal);
struct timeval interval;
interval.tv_sec =10;
interval.tv_usec = 10;

struct timeval value;
value.tv_sec = 10;
value.tv_usec = 10;

struct itimerval newValue;
newValue.it_interval = interval;
newValue.it_value = value;

int timer = setitimer(ITIMER_REAL, &newValue, NULL);
sleep(10);
while (1) {}

}
/* 
OUTPUT:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ cc 1a.c
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Timer expired in 10 seconds and 10 microsecond interval and signal number is 14
Timer expired in 10 seconds and 10 microsecond interval and signal number is 14
Timer expired in 10 seconds and 10 microsecond interval and signal number is 14
Timer expired in 10 seconds and 10 microsecond interval and signal number is 14
Timer expired in 10 seconds and 10 microsecond interval and signal number is 14
Timer expired in 10 seconds and 10 microsecond interval and signal number is 14
^C
gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ 
*/
