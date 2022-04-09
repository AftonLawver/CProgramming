#include <stdio.h>
#include <string.h>
#include <ctype.h>

void space_to_line(char* input_string);
void sort_and_print_array(int* input_array, int input_size);

int main() {
    space_to_line("Hi my name is Afton");

    printf("\n");

    int array_argument[6] = {7,2,8, 6, 11, 23};
    sort_and_print_array(array_argument, 6);

    return 0;
}

void space_to_line(char* input_string) {
    int string_length = strlen(input_string);
    for(int index = 0; index<string_length; index++) {
        int result = isspace(input_string[index]);
        if (result == 0) {
            printf("%c", input_string[index]);
        }
        else {
            printf("\n");
        }
    }
}

void sort_and_print_array(int* input_array, int input_size) {
    // Print array before sorting
    for(int i = 0; i < input_size; i++) {
        printf("%d\t", input_array[i]);
    }
    printf("\n");

    // Rearrange the elements by selection sort method
    int minimum_index, i, j;
    for (i = 0; i < input_size-1; i++) {
        minimum_index = i;
        for (j = i+1; j < input_size; j++) {
            if (input_array[j] < input_array[minimum_index]) {
                minimum_index = j;
            }
        }
        // Swap values
        int *xp = &input_array[minimum_index];
        int *yp = &input_array[i];
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    // Print array after sorting
    for(int i = 0; i < input_size; i++) {
        printf("%d\t", input_array[i]);
    }
    printf("\n");
}
