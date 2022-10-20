#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(int argc, char *argv[]) {
    if (argc > 2) {
        printf("Too many arguments supplied. \n");
        exit(0);
    }
    else if (argc < 2) {
        printf("Too few arguments supplied. \n");
        exit(0);
    }
    else {
        int f;
        if( (f = open(argv[1], O_RDONLY) ) < 0 )
        {
            perror( "open failed" );
            exit( 1 );
        }
        pid_t  pid;
        /* fork another process to get block size*/
        pid = fork();

        if (pid < 0) { /* error occurred */
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid == 0) { /* child process to get the size of the file in blocks*/
            int size = lseek(f, 0, SEEK_END);
            printf("From lseek(): The size of the file is: %d bytes.\n", size);
            printf("Blocks taken up by ls -s command:\n");
            execlp("/bin/ls", "ls", "-s", argv[1], NULL);
        }
        else { /* parent process */
            /* parent will wait for the child to complete */
            wait (NULL);
            printf ("First Child Complete\n");
            pid_t  pid;
            /* fork another process to get block size*/
            pid = fork();

            if (pid < 0) { /* error occurred */
                fprintf(stderr, "Fork Failed");
                exit(-1);
            }
            else if (pid == 0) { /* child process to get the size of the file in blocks*/
                struct stat stbuf;
                stat(argv[1], &stbuf);		/* 1 syscall */
                printf ("From stat: The size of the file is: %ld bytes.\n", stbuf.st_size);
                printf("Blocks taken up by stat command:\n");
                execlp("/bin/stat", "stat", "--format='%b'", argv[1], NULL);
            }
            else { /* parent process */
                /* parent will wait for the child to complete */
                wait (NULL);
                printf ("Second Child Complete\n");
                close(f);
                return 0;
            }
        }
    }
}