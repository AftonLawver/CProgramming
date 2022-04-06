#include <stdio.h>
#include <math.h>
int minimumNumber(int a, int b, int c, int d, int e);
int maximumNumber(int a, int b, int c, int d, int e);

int main() {
    int least;
    least = minimumNumber(4,1,7,56,3);
    printf("The minimum number is: %d\n", least);
    int greatest;
    greatest = maximumNumber(4,1,7,56,3);
    printf("The maximum number is: %d\n", greatest);
    return 0;
}

int minimumNumber(int a, int b, int c, int d, int e) {
    int leastNumber = a;
    if (b < leastNumber) {
        leastNumber = b;
    }
    if (c < leastNumber) {
        leastNumber = c;
    }
    if (d < leastNumber) {
        leastNumber = d;
    }
    if (e < leastNumber) {
        leastNumber = e;
    }
    return leastNumber;
}

int maximumNumber(int a, int b, int c, int d, int e) {
    int greatestNumber = a;
    if (b > greatestNumber) {
        greatestNumber = b;
    }
    if (c > greatestNumber) {
        greatestNumber = c;
    }
    if (d > greatestNumber) {
        greatestNumber = d;
    }
    if (e > greatestNumber) {
        greatestNumber = e;
    }
    return greatestNumber;
}