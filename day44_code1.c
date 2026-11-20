// Count spaces, digits, and special characters in a string.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000

int main(void) {
    char str[MAX_LEN];
    int spaces = 0, digits = 0, special = 0;

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: could not read input.\n");
        return 1;
    }

    /* Remove the trailing newline added by fgets */
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str[i];

        if (ch == ' ')
            spaces++;
        else if (isdigit(ch))
            digits++;
        else if (!isalpha(ch))
            special++;
    }

    printf("Spaces=%d, Digits=%d, Special=%d\n", spaces, digits, special);

    return 0;
}