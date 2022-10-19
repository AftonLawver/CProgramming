#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc > 3) {
        printf("Too many arguments supplied. \n");
        exit(0);
    }
    else if (argc < 3) {
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
            execlp("/bin/mv", "mv", argv[1], argv[2], NULL);
        }
        else { /* parent process */
            /* parent will wait for the child to complete */
            wait (NULL);
            printf ("Child Complete\n");
            return 0;
        }

    }

}


