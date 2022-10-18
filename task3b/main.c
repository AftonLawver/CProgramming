#include<stdio.h>
#include<dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

/* Simple shell program that run ls command
 - Create a child process
 - Parent wait child process to terminate
 - calls the ls command */
int main() {
    pid_t  pid;
    /* fork another process */
    pid = fork();
    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0) { /* child process */
        execlp("/bin/ls", "ls", NULL);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait (NULL);
        printf ("Child Complete\n");
        exit(0); 	       }
}
