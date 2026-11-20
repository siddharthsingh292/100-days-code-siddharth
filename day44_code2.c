// Replace spaces with hyphens in a string.
#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(void) {
    char str[MAX_LEN];

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: could not read input.\n");
        return 1;
    }

    /* Remove the trailing newline added by fgets */
    str[strcspn(str, "\n")] = '\0';

    /* Replace each space with a hyphen */
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            str[i] = '-';
    }

    printf("Result: %s\n", str);

    return 0;
}