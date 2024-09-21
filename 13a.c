/*
============================================================================
Name : 13a.c
Author : Gitika Pinjani
Description : 13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 21th Sept, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void handleSigstop(int signum) {
    printf(" catch SIGSTOP\n");
}

int main() {

    if (signal(SIGSTOP, handleSigstop) == SIG_ERR) {
        printf("Can't catch SIGSTOP.\n");
    }

    printf("Process PID: %d is running..\n", getpid());

    while (1) {
        printf("Running...%d\n",getpid());
        sleep(3);
    }

    return 0;
}


/*
Output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
Can't catch SIGSTOP.
Process PID: 5769 is running..
Running...5769
Running...5769
Running...5769
Running...5769
Running...5769
Running...5769

*/
