#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        printf("You entered one argument!\n");
    }
    else {
        printf("One argument is required!\n");
    }
    return 0;
}
