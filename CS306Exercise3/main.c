#include <stdio.h>

int main() {
    FILE *file;
    char path[100];

    int characters = 0;
    int words = 0;
    int lines = 0;
    char c;
    printf("Enter source file path: ");
    scanf("%s", path);
    file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening the file");
        return(-1);
    }
    else {
        while ((c = fgetc(file)) != EOF) {
            characters ++;

            if (c == '\n' || c == '\0') {
                lines++;
            }
            if (c == ' ' || c == '\t' || c == '\n' || c == '\0') {
                words++;
            }
        }
        if (characters > 0) {
            words ++;
            lines ++;
        }
    }

    printf("The number of lines in the file: %d\n", lines);
    printf("The number of words in the file: %d\n", words);
    printf("The number of characters in the file: %d\n", characters);

    return 0;
}
