#include <stdio.h>
int fun(int *pointer1, int *pointer2);

int main() {
    int a = 10;
    int b = 20;

    printf("Before calling function: a = %d, b = %d\n", a, b);
    fun(&a, &b);
    printf("After calling function: a = %d, b = %d\n", a, b );
}

// call by reference example
int fun(int *pointer1, int *pointer2) {
    *pointer1 = 20;
    *pointer2 = 10;
}
