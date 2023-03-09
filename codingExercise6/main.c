#include <stdio.h>
#include <ctype.h>
#include <string.h>

void modifyText(char *inputString);

int main() {
    char string[64];
    printf("%s","Enter some text:\n");
    fgets(string, 64, stdin);
    string[strlen(string)-1]='\0';
    modifyText(string);
    printf("%s", string);
    return 0;
}

void modifyText(char *inputString) {
    while(*inputString) {
        *inputString = toupper(*inputString);
        if (*inputString == ' ') {
            *inputString = '_';
            inputString++;
        }
        else {
            inputString++;
        }

    }
}


