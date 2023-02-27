#include <stdio.h>

int main() {
    int input;
    printf("Input a positive integer:\n");
    scanf("%d", &input);
    printf("The number you input is %s", (input % 2 == 0) ? "even" : "odd");
    return 0;
}
