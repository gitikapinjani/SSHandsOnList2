#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int pipefdes[2];
    pid_t pid1, pid2;

 pipe(pipefdes);

    pid1 = fork();
   

    if (pid1 == 0) {
       close(STDOUT_FILENO);
       if (fcntl(pipefdes[1], F_DUPFD, STDOUT_FILENO) == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }

      close(pipefdes[0]);
        close(pipefdes[1]);
        execlp("ls", "ls", "-l", NULL);
      
    }

   
    pid2 = fork();
        if (pid2 == 0) {
    
        close(STDIN_FILENO);
        if (fcntl(pipefdes[0], F_DUPFD, STDIN_FILENO) == -1) {
            perror("fcntl");
            exit(EXIT_FAILURE);
        }
        close(pipefdes[0]);
        close(pipefdes[1]);
        execlp("wc", "wc", NULL);

    }


    close(pipefdes[0]);
    close(pipefdes[1]);

   
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}

/*
output:

gitikapinjani@gitikapinjani-Victus-by-HP-Gaming-Laptop-15-fa0xxx:~/HandsOnList2-SS$ ./a.out
     80     708    5271

*/
