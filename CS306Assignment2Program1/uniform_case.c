// Afton Lawver
// SIU851463587

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int isUpper(int inputCharacter);


int main(int argc, char *argv[]) {
    int x = argv[1][0];

    // allocate new array for new string in memory
    char *ptr = malloc((strlen(argv[1])) * sizeof(char));
    if (ptr == NULL) {
        perror("malloc() failed");
        exit(EXIT_FAILURE);
    }
    if (isUpper(x) == 1) {
        printf("First letter is uppercase.\n");
        for (int i = 0; argv[1][i] != '\0'; i++) {
            ptr[i] = *argv[i] + 32;
        }
        int stringLength = strlen(ptr);
        ptr[stringLength] = '\0';

    }
    else {
        printf("First letter is lowercase.\n");
        for (int i = 0; argv[1][i] != '\0'; i++) {
            ptr[i] = *argv[i] - 32;
        }
        int stringLength = strlen(ptr);
        ptr[stringLength] = '\0';
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

int convertToUpper(char inputCharacter) {
    int upperCaseCharacter = inputCharacter + 32;
}
