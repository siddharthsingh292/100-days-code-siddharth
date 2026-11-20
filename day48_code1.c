//Check if one string is a rotation of another.

#include <stdio.h>
#include <string.h>

#define MAX 1000

int isRotation(const char *s1, const char *s2) {
    // Rotations must have the same length
    if (strlen(s1) != strlen(s2))
        return 0;

    // Build s1 + s1
    char doubled[2 * MAX + 1];
    strcpy(doubled, s1);
    strcat(doubled, s1);

    // s2 is a rotation of s1 if it is a substring of s1 + s1
    return strstr(doubled, s2) != NULL;
}

int main() {
    char str1[MAX], str2[MAX];
    char choice;

    printf("=====================================\n");
    printf("      STRING ROTATION CHECKER\n");
    printf("=====================================\n");

    do {
        printf("\nEnter first string  : ");
        fgets(str1, MAX, stdin);
        str1[strcspn(str1, "\n")] = '\0';   // remove newline

        printf("Enter second string : ");
        fgets(str2, MAX, stdin);
        str2[strcspn(str2, "\n")] = '\0';

        if (strlen(str1) == 0 || strlen(str2) == 0) {
            printf("\nError: Strings cannot be empty. Please try again.\n");
        } else if (strlen(str1) != strlen(str2)) {
            printf("\nResult: Not rotation (lengths are different)\n");
        } else if (isRotation(str1, str2)) {
            printf("\nResult: Rotation\n");
        } else {
            printf("\nResult: Not rotation\n");
        }

        printf("\nDo you want to check another pair? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Rotation Checker. Goodbye!\n");
    return 0;
}