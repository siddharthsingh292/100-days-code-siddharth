//Check if two strings are anagrams of each other.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int areAnagrams(const char *s1, const char *s2) {
    int count[26] = {0};

    // Count letters of first string (+1)
    for (int i = 0; s1[i] != '\0'; i++) {
        if (isalpha((unsigned char)s1[i]))
            count[tolower((unsigned char)s1[i]) - 'a']++;
    }

    // Subtract letters of second string (-1)
    for (int i = 0; s2[i] != '\0'; i++) {
        if (isalpha((unsigned char)s2[i]))
            count[tolower((unsigned char)s2[i]) - 'a']--;
    }

    // If all counts are zero, they are anagrams
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    char str1[MAX], str2[MAX];
    char choice;

    printf("=====================================\n");
    printf("      ANAGRAM CHECKER PROGRAM\n");
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
        } else if (areAnagrams(str1, str2)) {
            printf("\nResult: Anagrams\n");
        } else {
            printf("\nResult: Not anagrams\n");
        }

        printf("\nDo you want to check another pair? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Anagram Checker. Goodbye!\n");
    return 0;
}