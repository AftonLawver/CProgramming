#include <stdio.h>
#include <unistd.h>

int main() {

    //Initialize variables
    int input;
    int count = 0;
    int sum = 0;

    printf("Enter a positive integer number or enter -1 to quit and calculate average: ");
    scanf("%d", &input);
    while(input != -1) {
        count +=1;
        sum += input;
        printf("Enter another positive integer or enter -1 to quit and calculate average: ");
        scanf("%d", &input);
        continue;
    }
    if (count == 0) {
        printf("No numbers to calculate average with.");
        return 1;
    }

    double average = (double)sum / (double)count;

    printf("The average of these numbers is: %f\n", average);
    printf("Press ENTER key to Continue\n");
    char button;

    // Purge the remaining whitespace in buffer
    getchar();

    scanf("%c", &button);
    if (button == 10) {
        return 0;
    }
}

