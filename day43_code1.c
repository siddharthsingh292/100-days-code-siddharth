//Reverse a string.

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int main(void) {
    char str[MAX_LEN];

    printf("Enter a string: ");

    /* fgets is safer than gets/scanf and allows spaces */
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error: could not read input.\n");
        return 1;
    }

    /* Remove the trailing newline added by fgets */
    str[strcspn(str, "\n")] = '\0';

    int len = (int)strlen(str);

    if (len == 0) {
        printf("You entered an empty string.\n");
        return 0;
    }

    /* Swap characters from both ends moving toward the center */
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}