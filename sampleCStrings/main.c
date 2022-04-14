#include <stdio.h>
int string_length(char* word);
void min_and_max_of_array(int num[], int size_of_array);

int main() {
    char my_word[10] = "Hello";
    int length = string_length(my_word);
    printf("Length of word: %d\n", length);

    int my_array [] = {2,7,6,9};
    min_and_max_of_array(my_array, 4);
    return 0;
}

int string_length(char* word) {
    int i= 0;
    int count = 0;
    for (i=0; word[i] != '\0'; ++i) {
        ++count;
    }
    return count;
}

void min_and_max_of_array(int num[], int size_of_array) {
    int minimum_value = num[0];
    int maximum_value = num[0];
    int i;
    for (i=1; i <= size_of_array-1; ++i) {
        if (num[i] < minimum_value) {
            minimum_value = num[i];
        }
        else if (num[i] > maximum_value) {
            maximum_value = num[i];
        }
    }
    printf("The minimum value is: %d\n", minimum_value);
    printf("The maximum value is: %d\n", maximum_value);
}
