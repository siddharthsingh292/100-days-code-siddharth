//Convert a lowercase string to uppercase without using built-in functions.

#include <stdio.h>

int main() {
    char str[1000];
    int i;

    printf("=== Lowercase to Uppercase Converter ===\n");
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline added by fgets (manual, no built-ins) */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }

    if (str[0] == '\0') {
        printf("You did not enter anything. Please run the program again.\n");
        return 0;
    }

    /* Convert: 'a'-'z' have ASCII 97-122, 'A'-'Z' have 65-90 (difference of 32) */
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    printf("\nUppercase: %s\n", str);

    return 0;
}