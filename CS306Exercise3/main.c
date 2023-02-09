#include <stdio.h>

int main() {
    char filename[100];
    scanf("%s", filename);
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("Error opening the file");
        return(-1);
    }
    int characters = 0;
    int words = 0;
    int lines = 0;
    char line[102];
    fgets(line, 102, filename);


    fgets


    return 0;
}
