#include <stdio.h>

int main() {
    float input;

    printf("Enter a positive integer:\n");
    scanf("%f", &input);
    float result1 = input * 5;
    printf("Multiplied by 5: %.1f\n", result1);
    float result2 = result1/3;
    printf("Divided by 3: %.1f\n", result2);

    return 0;
}
