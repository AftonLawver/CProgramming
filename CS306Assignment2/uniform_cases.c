// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isUpper(int inputCharacter);
char *convertToUpper(char *inputString, char *outputString);
char *convertToLower(char *inputString, char *outputString);
void print_list(char ** data);

int main(int argc, char *argv[]) {
    int numberOfArguments = argc - 1;
    int columns = 25;
    // allocate new array for new string in memory
    char **dynamicCharArray = (char**)malloc((numberOfArguments * sizeof(char*)));
        if (dynamicCharArray == NULL) {
        perror("malloc() failed");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i<=numberOfArguments; i++) {
        dynamicCharArray[i] = (char*)malloc(columns * sizeof(char));
    }

    for (int i = 0; i < numberOfArguments; i++) {
        if(isUpper(argv[i+1][0])) {
            dynamicCharArray[i] = convertToUpper(argv[i+1],dynamicCharArray[i]);
        }
        else {
            dynamicCharArray[i] = convertToLower(argv[i+1],dynamicCharArray[i]);
        }
    }
    print_list(dynamicCharArray);
    for (int i = 0; i < numberOfArguments; i++) {
        free(dynamicCharArray[i]);
    }
    free(dynamicCharArray);
    return 0;
}
//
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
        if (isUpper(inputString[i])) {
            outputString[i] = inputString[i];
        }
        else {
            outputString[i] = inputString[i] - 32;
        }
        i++;
    }
    outputString[strlen(outputString)] = '\0';
    return outputString;
}

char *convertToLower(char *inputString, char *outputString) {
    outputString[0] = inputString[0];
    int i = 1;
    while (inputString[i] != '\0') {
        if (isUpper(inputString[i])) {
            outputString[i] = inputString[i] + 32;
        }
        else {
            outputString[i] = inputString[i];
        }
        i++;
    }
    outputString[strlen(outputString)] = '\0';
    return outputString;
}

void print_list(char ** data) {
    printf("List of Values:\n");
    for (int i = 0; *data[i] != '\0'; i++) {
        for (int j = 0; data[i][j] != '\0'; j++) {
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
}