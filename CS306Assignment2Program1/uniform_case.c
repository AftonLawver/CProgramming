// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isUpper(int inputCharacter);
char *convertToUpper(char *inputString, char *outputString);
char *convertToLower(char *inputString, char *outputString);

int main(int argc, char *argv[]) {
    int firstCharacter = argv[1][0];

    // allocate new array for new string in memory
    char *ptr = malloc((strlen(argv[1])) * sizeof(char));
    if (ptr == NULL) {
        perror("malloc() failed");
        exit(EXIT_FAILURE);
    }
    if (isUpper(firstCharacter) == 1) {
        printf("First letter is uppercase.\n");
        ptr = convertToUpper(argv[1], ptr);
    }
    else {
        printf("First letter is lowercase.\n");
        ptr = convertToLower(argv[1], ptr);
    }
    printf("New String: %s", ptr);
    return 0;
}

int isUpper(int inputCharacter) {
    if (inputCharacter >= 65 && inputCharacter <= 91) {
        return 1;
    }
    else {
        return 0;
    }
}

char *convertToUpper(char *inputString, char *outputString) {
    outputString[0] = inputString[0];
    int i = 1;
    while (inputString[i] != '\0') {
        outputString[i] = inputString[i] - 32;
        i++;
    }
    outputString[strlen(outputString)-1] = '\0';
    return outputString;
}

char *convertToLower(char *inputString, char *outputString) {
    outputString[0] = inputString[0];
    int i = 1;
    while (inputString[i] != '\0') {
        outputString[i] = inputString[i] + 32;
        i++;
    }
    outputString[strlen(outputString)-1] = '\0';
    return outputString;
}
