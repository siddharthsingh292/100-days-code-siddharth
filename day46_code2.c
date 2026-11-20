// Find the first repeating character in a string.

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(void) {
    char str[MAX_LEN];
    int seen[26] = {0};  /* seen[0] for 'a', seen[1] for 'b', ... */

    printf("Enter a string: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: could not read input.\n");
        return 1;
    }

    /* Remove the trailing newline added by fgets */
    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        /* Only consider lowercase letters */
        if (ch >= 'a' && ch <= 'z') {
            if (seen[ch - 'a']) {
                printf("First repeating character: %c\n", ch);
                return 0;
            }
            seen[ch - 'a'] = 1;
        }
    }

    printf("No repeating lowercase character found.\n");

    return 0;
}