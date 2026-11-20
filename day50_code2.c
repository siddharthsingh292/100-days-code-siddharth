//Print all sub-strings of a string.
#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char str[MAX];
    char choice;

    printf("=====================================\n");
    printf("      ALL SUBSTRINGS PROGRAM\n");
    printf("=====================================\n");

    do {
        printf("\nEnter a string: ");
        fgets(str, MAX, stdin);
        str[strcspn(str, "\n")] = '\0';   // remove newline

        int n = strlen(str);

        if (n == 0) {
            printf("\nError: String cannot be empty. Please try again.\n");
        } else {
            int count = 0;

            printf("\nSubstrings: ");
            for (int i = 0; i < n; i++) {           // starting index
                for (int j = i; j < n; j++) {       // ending index
                    for (int k = i; k <= j; k++)
                        putchar(str[k]);

                    count++;
                    if (count < n * (n + 1) / 2)    // no comma after the last one
                        printf(",");
                }
            }
            printf("\n\nTotal substrings: %d\n", count);
        }

        printf("\nDo you want to try another string? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Substrings program. Goodbye!\n");
    return 0;
}