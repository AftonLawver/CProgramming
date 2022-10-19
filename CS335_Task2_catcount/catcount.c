#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc > 2) {
        printf("Too many arguments supplied. \n");
        exit(0);
    }
    pid_t  pid;
    /* fork another process */
    pid = fork();

    if (pid < 0) { /* error occurred */
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid == 0) { /* child process */
        execlp("/bin/cat", "cat", argv[1], NULL);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait (NULL);
        printf ("Child Complete\n");
        pid_t  pid2;
        /* fork another process */
        pid2 = fork();

        if (pid2 < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid2 == 0) { /* child process */
            execlp("/usr/bin/wc", "wc", argv[1], NULL);
        }
        else { /* parent process */
            /* parent will wait for the child to complete */
            wait (NULL);
            printf ("Child Complete\n");
            exit(0);
        }
    return 0;
    }
}

