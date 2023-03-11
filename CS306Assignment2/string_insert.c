// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(char *stringInput);
char* string_n_copy(char* destination, const char* source);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong number of arguments\n");
        return 1;
    }
    else {
        int integerArgument = atoi(argv[2]);
        int lengthOfString1 = string_length(argv[1]);
        int lengthOfString2 = string_length(argv[3]);
        int totalLength = lengthOfString1 + lengthOfString2 +1;
        char* charPointer;
        if (integerArgument < lengthOfString1) {
            charPointer = (char *) malloc(sizeof(char) * (lengthOfString1 + lengthOfString2 + 1));
            for (int i = 0; i < totalLength; i++) {
                if (i == integerArgument) {
                    charPointer = strcpy(charPointer, argv[3]);
                    i+=lengthOfString2 + 1;
                    printf("")
                }
                else {
                    printf("integer does not equal 0.\n");
                }
            }
        }
        else {
            printf("Argument 2 is greater than the length of the first string\n");
            exit(EXIT_FAILURE);
        }
        printf("New string: %s\n", charPointer);
        return 0;
    }
}

int string_length(char *stringInput) {
    int i = 0;
    while (stringInput[i] != '\0') {
        i++;
    }
    return i;
}

char* string_n_copy(char* destination, const char* source)
{
    if (destination == NULL) {
        return NULL;
    }

    // take a pointer pointing to the beginning of the destination string
    char *ptr = destination;

    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
    return ptr;
}

