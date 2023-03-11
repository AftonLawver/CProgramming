// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_length(char *stringInput);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Wrong number of arguments. Please enter 3 arguments.\n");
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
            int currentPositionFirstString = 0;
            int currentPositionSecondString = 0;
            for (int i = 0; i < totalLength; i++) {
                if (integerArgument > i) {
                    charPointer[i] = argv[1][currentPositionFirstString];
                    currentPositionFirstString++;
                }
                else if (i == integerArgument) {
                    while (argv[3][currentPositionSecondString] != '\0') {
                        charPointer[i] = argv[3][currentPositionSecondString];
                        currentPositionSecondString++;
                        i++;
                    }
                    i--;
                }
                else {
                    charPointer[i] = argv[1][currentPositionFirstString];
                    currentPositionFirstString++;
                }
            }
        }
        else {
            printf("Argument 2 is greater than the length of the first string\n");
            exit(EXIT_FAILURE);
        }
        charPointer[totalLength] = '\0';
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

