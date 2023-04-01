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
        return EXIT_FAILURE;
    }
    const char *filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("File does not exist\n");
        return EXIT_FAILURE;
    }
    else {
        int number_of_tokens = 0;
        while(1) {
            char *my_word = get_token(fd);
            if (my_word == NULL) {
                break;
            }
            printf("%s", my_word);
            number_of_tokens++;
            free(my_word);
        }
        printf("\n");
        printf("Number of tokens/words: %d", number_of_tokens);
        close(fd);
    }
    return 0;
}

char *get_token(int fd) {
    static int buffer_location = 0;
    static ssize_t buffer_count = 0;
    static char input_buffer[100];

    int capacity = 50;
    char *token_buffer = malloc(capacity * sizeof(char));
    if (token_buffer == NULL) {
        perror("malloc failed");
        exit(1);
    }
    int token_length = 0;

    int is_reading_token = 1;
    while(is_reading_token) {
        if (buffer_count == 0) {
            buffer_count = read(fd, input_buffer, 100);
            if(buffer_count == -1) {
                perror("Error");
                return NULL;
            }
            buffer_location = 0;
            if (buffer_count <= 0) {
                is_reading_token = 0;
                break;
            }
        }
        char current_char = input_buffer[buffer_location++];
        buffer_count--;

        int whitespace_character = (current_char == ' ' || current_char == '\n' || current_char == '\t');
        if (!whitespace_character ||  token_length > 0) {
            if (token_length == capacity) {
                capacity += 10;
                token_buffer = (char *)realloc(token_buffer, capacity * sizeof(char));
            }
            token_buffer[token_length++] = current_char;
            if (whitespace_character) {
                is_reading_token = 0;
            }
        }
    }
    if (token_length == 0) {
        free(token_buffer);
        return NULL;
    }
    token_buffer[token_length] = '\0';
    return token_buffer;
}

