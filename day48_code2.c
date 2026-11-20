//Reverse each word in a sentence without changing the word order.

#include <stdio.h>
#include <string.h>

#define MAX 1000

// Reverse characters of str[start..end] in place
void reverseRange(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseEachWord(char *sentence) {
    int i = 0, n = strlen(sentence);

    while (i < n) {
        // Skip spaces
        while (i < n && sentence[i] == ' ')
            i++;

        int start = i;

        // Find end of the word
        while (i < n && sentence[i] != ' ')
            i++;

        if (i > start)
            reverseRange(sentence, start, i - 1);
    }
}

int main() {
    char sentence[MAX];
    char choice;

    printf("=====================================\n");
    printf("      WORD REVERSER PROGRAM\n");
    printf("=====================================\n");

    do {
        printf("\nEnter a sentence: ");
        fgets(sentence, MAX, stdin);
        sentence[strcspn(sentence, "\n")] = '\0';   // remove newline

        if (strlen(sentence) == 0) {
            printf("\nError: Sentence cannot be empty. Please try again.\n");
        } else {
            reverseEachWord(sentence);
            printf("\nResult: %s\n", sentence);
        }

        printf("\nDo you want to try another sentence? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n');   // clear input buffer

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Word Reverser. Goodbye!\n");
    return 0;
}