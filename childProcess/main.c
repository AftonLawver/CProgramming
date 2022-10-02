#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>


int main() {

    pid_t pid;
/* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0) { /* child process */
        execlp("/home/afton21/Desktop/CProgramming/childProcess/averageOfNumbers.exe", NULL);
    }
    else { /* parent process */
/* parent will wait for the child to complete */
        wait (NULL);

        printf ("Child Complete");
        exit(0); }
    return 0;
}
