#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>


int main(int argc, char *argv[]) {
    int f;
    if (argc > 2) {
        printf("Too many arguments supplied. \n");
        exit(0);
    }
    else if (argc < 2) {
        printf("Too few arguments supplied. \n");
        exit(0);
    }
    else {
        pid_t  pid;
        /* fork another process */
        pid = fork();

        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid == 0) { /* child process */
            f = open("seek", O_RDWR);
            lseek(f, 5, SEEK_CUR);
        }
        else { /* parent process */
            /* parent will wait for the child to complete */
            wait (NULL);
            printf ("Child Complete\n");
            return 0;
        }

    }

}