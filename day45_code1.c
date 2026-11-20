// Count the frequency of a specific character in a string.

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(void) {
    char str[MAX_LEN];
    char target;
    int count = 0;

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: could not read input.\n");
        return 1;
    }

    /* Remove the trailing newline added by fgets */
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the character to count: ");

    /* Leading space in " %c" skips any leftover whitespace/newline */
    if (scanf(" %c", &target) != 1) {
        printf("Error: could not read the character.\n");
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target)
            count++;
    }

    printf("Frequency of '%c' = %d\n", target, count);

    return 0;
}