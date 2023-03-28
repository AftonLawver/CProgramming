#include <stdio.h>

char *get_token(int fd);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Please provide the filename as a single command line argument.");
    }
    const char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("File does not exist\n");
        return 0;
    }
    else {
//        printf("File %s exists\n", filename);
        while (1) {
            // call get_token until returns null


        }
    }

    return 0;
}

char *get_token(int fd) {
    int capacity = 50;
    // dynamically allocate a buffer of 50 bytes;
    char *buffer = (char *)malloc(capacity * sizeof(char));
    if (buffer == NULL) {
        perror("malloc failed");
        exit(1);
    }
}

