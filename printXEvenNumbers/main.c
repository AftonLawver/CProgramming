#include <stdio.h>
int printValue(int number);

int main() {
    int value;
    printf("Enter a number: \n");
    scanf("%d", &value);
    printValue(value);
    return 0;
}

int printValue(int number) {
    if (number == 0) {
        return 2;
    }
    else {
        printf("%d\n", number * 2);
        return printValue(number-1);
    }
}
