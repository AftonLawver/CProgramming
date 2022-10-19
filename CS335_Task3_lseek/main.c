#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>
#include <fcntl.h>


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
        int size = lseek(f, 0, SEEK_END);
        printf("The size of the file is: %d\n", size);
        close(f);
    }
}