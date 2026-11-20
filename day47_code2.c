//Find the longest word in a sentence.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int main() {
    char sentence[MAX];
    char longest[MAX] = "";
    char current[MAX];
    char choice;

    printf("=====================================\n");
    printf("      LONGEST WORD FINDER\n");
    printf("=====================================\n");

    do {
        printf("\nEnter a sentence: ");
        fgets(sentence, MAX, stdin);
        sentence[strcspn(sentence, "\n")] = '\0';   // remove newline

        longest[0] = '\0';
        int maxLen = 0, len = 0;

        for (int i = 0; ; i++) {
            if (isalnum((unsigned char)sentence[i])) {
                current[len++] = sentence[i];
            } else {
                // word ended (space, punctuation, or end of string)
                if (len > 0) {
                    current[len] = '\0';
                    if (len > maxLen) {          // first longest word wins on ties
                        maxLen = len;
                        strcpy(longest, current);
                    }
                    len = 0;
                }
                if (sentence[i] == '\0')
                    break;
            }
        }

        if (maxLen == 0) {
            printf("\nError: No words found. Please try again.\n");
        } else {
            printf("\nLongest word : %s\n", longest);
            printf("Length       : %d characters\n", maxLen);
        }

        printf("\nDo you want to try another sentence? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using Longest Word Finder. Goodbye!\n");
    return 0;
}