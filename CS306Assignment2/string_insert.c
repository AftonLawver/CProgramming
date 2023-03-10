// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        perror("Wrong number of arguments\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Correct number of arguments\n");
    }
    return 0;
}