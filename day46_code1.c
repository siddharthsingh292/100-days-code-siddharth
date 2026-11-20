// Remove vowels from a string.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

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

    int j = 0;  /* write position for the result */

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = (char)tolower((unsigned char)str[i]);

        /* Keep the character only if it is not a vowel */
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            str[j++] = str[i];
        }
    }

    str[j] = '\0';  /* terminate the shortened string */

    printf("Result: %s\n", str);

    return 0;
}