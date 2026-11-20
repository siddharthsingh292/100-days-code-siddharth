// Count vowels and consonants in a string.
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char str[1000];
    int vowels = 0, consonants = 0;

    printf("=== Vowel & Consonant Counter ===\n");
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Remove trailing newline added by fgets */
    str[strcspn(str, "\n")] = '\0';

    if (strlen(str) == 0) {
        printf("You did not enter anything. Please run the program again.\n");
        return 0;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower((unsigned char)str[i]);

        if (isalpha((unsigned char)ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        /* digits, spaces and symbols are ignored */
    }

    printf("\nResult: Vowels=%d, Consonants=%d\n", vowels, consonants);

    return 0;
}