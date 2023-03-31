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
        }

//        while (1) {
            // call get_token until returns null
            // if  return from get_token is null then break loop
            // else write the current token to the stout (fd=1), and then free the token.



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
    int i = 0;
    while(1) {
        // resize the buffer if the capacity is reached.
        if (i == capacity) {
            capacity += 10;
            buffer = (char *)realloc(buffer, capacity * sizeof(char));
        }
        int read_return = read(fd, &buffer[i], 1);
        if(read_return == -1) {
            perror("Error");
            return NULL;
        }
        // no more characters to read from file (EOF)
        else if (read_return == 0 && i > 0) {
            buffer[i] = '\n';
            return buffer;
        }
        else if (read_return == 0) {
            return NULL;
        }
        else if (buffer[i] == '\n' || buffer[i] == '\t' || buffer[i] == ' ') {
            buffer[i] = '\n';
            return buffer;
        }
        i++;
    }



}

