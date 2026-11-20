#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char name[MAX];
    char choice;

    printf("=====================================\n");
    printf("         NAME INITIALS PROGRAM\n");
    printf("=====================================\n");

    do {
        printf("\nEnter a full name: ");
        fgets(name, MAX, stdin);
        name[strcspn(name, "\n")] = '\0';   // remove newline

        int found = 0;
        char initials[MAX] = "";
        int pos = 0;

        for (int i = 0; name[i] != '\0'; i++) {
            // A new word starts at a letter that follows a space (or the start)
            if (isalpha((unsigned char)name[i]) &&
                (i == 0 || isspace((unsigned char)name[i - 1]))) {
                initials[pos++] = toupper((unsigned char)name[i]);
                initials[pos++] = '.';
                found = 1;
            }
        }
        initials[pos] = '\0';

        if (!found) {
            printf("\nError: No valid name entered. Please try again.\n");
        } else {
            printf("\nInitials: %s\n", initials);
        }

        printf("\nDo you want to try another name? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Name Initials program. Goodbye!\n");
    return 0;
}