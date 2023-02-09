#include <stdio.h>
#include <ctype.h>

int get_string_length(char *original_string);
char* convert_string_to_uppercase(char *original_string);

int main() {
    char my_string[] = "Afton";
    int result = get_string_length(my_string);
    printf("The string's length is: %d\n\n", result);
    printf("The old string is: %s\n\n", my_string);

    char* my_uppercase_string = convert_string_to_uppercase(my_string);
    printf("The new string is: %s\n\n", my_uppercase_string);
    return 0;
}

int get_string_length(char *original_string) {
    int length = 0;
    int i = 0;
    while (original_string[i] != '\0') {
        i++;
        length++;
    }
    return length;
}

char* convert_string_to_uppercase(char *original_string) {
    int i = 0;
    while (original_string[i] != '\0') {
        char current_character = original_string[i];
        char uppercase_character = toupper(current_character);
        original_string[i] = uppercase_character;
        i++;
    }
    return original_string;

}


