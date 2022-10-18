#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>

/* Simple shell program that run ls command
 - Create a child process
 - Parent wait child process to terminate
 - calls the ls command */

int main() {
    char command[10];
    time_t current_time;
    char* c_time_string;
    current_time = time(NULL);

    // Convert to local time format.
    c_time_string = ctime(&current_time);
    printf("%s, %s", "Afton Lawver",c_time_string);
    do {
        printf("Type a UNIX command such as ls, ps, pwd, etc. Or enter quit to exit.\n");
        scanf("%s", command);
        pid_t  pid;
        /* fork another process */
        pid = fork();
        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid == 0) { /* child process */
            char filepath[] = "/usr/bin/";
            strcat(filepath, command);
            printf("full path: %s", filepath);
            execlp(filepath, command, NULL);
        }
        else { /* parent process */
            /* parent will wait for the child to complete */
            wait (NULL);
            printf ("Child Complete\n");
            continue; 	       }
    }
    while (strcmp(&command, "quit") != 0);
}
