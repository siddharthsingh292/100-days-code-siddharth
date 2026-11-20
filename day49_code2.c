//Print initials of a name with the surname displayed in full.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char name[MAX];
    char choice;

    printf("=====================================\n");
    printf("      INITIALS + SURNAME PROGRAM\n");
    printf("=====================================\n");

    do {
        printf("\nEnter a full name: ");
        fgets(name, MAX, stdin);
        name[strcspn(name, "\n")] = '\0';   // remove newline

        // Trim trailing spaces
        int end = strlen(name) - 1;
        while (end >= 0 && isspace((unsigned char)name[end]))
            name[end--] = '\0';

        if (end < 0) {
            printf("\nError: No name entered. Please try again.\n");
        } else {
            // Find the start of the surname (last word)
            int surnameStart = end;
            while (surnameStart > 0 && !isspace((unsigned char)name[surnameStart - 1]))
                surnameStart--;

            char result[MAX] = "";
            int pos = 0;

            // Initials of all words before the surname
            for (int i = 0; i < surnameStart; i++) {
                if (isalpha((unsigned char)name[i]) &&
                    (i == 0 || isspace((unsigned char)name[i - 1]))) {
                    result[pos++] = toupper((unsigned char)name[i]);
                    result[pos++] = '.';
                }
            }

            // Add a space between initials and surname (only if initials exist)
            if (pos > 0)
                result[pos++] = ' ';

            // Surname: first letter uppercase, rest lowercase
            for (int i = surnameStart; name[i] != '\0'; i++) {
                if (i == surnameStart)
                    result[pos++] = toupper((unsigned char)name[i]);
                else
                    result[pos++] = tolower((unsigned char)name[i]);
            }
            result[pos] = '\0';

            printf("\nResult: %s\n", result);
        }

        printf("\nDo you want to try another name? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Initials + Surname program. Goodbye!\n");
    return 0;
}
