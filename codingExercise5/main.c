#include <stdio.h>

int *primes() {
    static int p[5] = {1,2,3,4,5};
    return p;
}

int main() {
    int x;
    int *array;
    array = primes();
    for(x=0; x<5; x++) {
        printf("%d\n", array[x]);
    }
    return 0;
}
