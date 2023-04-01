// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_token(int fd);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        perror("Please provide the filename as a single command line argument.");
    }
    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File does not exist\n");
        return EXIT_FAILURE;
    }
    else {
        while(1) {
            char *my_word = get_token(fd);
            if (my_word == NULL) {
                break;
            }
            printf("%s", my_word);
            free(my_word);
        }
    }
    return 0;
    }

char *get_token(int fd) {
    int capacity = 50;
    // dynamically allocate a buffer of 50 bytes;
    char *token_buffer = (char *)malloc(capacity * sizeof(char));
    if (token_buffer == NULL) {
        perror("malloc failed");
        exit(1);
    }
    int i = 0;
    while(1) {
        // resize the buffer if the capacity is reached.
        if (i == capacity) {
            capacity += 10;
            token_buffer = (char *)realloc(token_buffer, capacity * sizeof(char));
        }
        int read_return = read(fd, &token_buffer[i], 1);
        if(read_return == -1) {
            perror("Error");
            return NULL;
        }
        // no more characters to read from file (EOF)
        else if (read_return == 0 && i > 0) {
            token_buffer[i] = '\n';
            return token_buffer;
        }
        else if (read_return == 0) {
            return NULL;
        }
        else if (token_buffer[i] == '\n' || token_buffer[i] == '\t' || token_buffer[i] == ' ') {
            token_buffer[i] = '\n';
            return token_buffer;
        }
        i++;
    }
}

