#include <stdio.h>

int main() {
    int input;
    printf("Enter an integer:\n");
    scanf("%d", &input);
    printf("The floating point value is: %0.1f", (float)input);
    return 0;
}
