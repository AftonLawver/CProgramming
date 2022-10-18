#include <stdio.h>

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
        execlp("/bin/cat", "cat", NULL);
    }
    else { /* parent process */
        /* parent will wait for the child to complete */
        wait (NULL);
        printf ("Child Complete\n");
        exit(0); 	       }
    //Reads file 100 characters
    char buff[100],fn[10];
    int fd,n;

    printf("Enter the filename\n");

    scanf("%s",fn);

    fd = open(fn,O_RDONLY);
    n = read(fd,buff,100);

    n = write(1,buff,n);
    printf("%d\n",n);

    close(fd);
    return 0;
}
