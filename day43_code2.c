// Check if a string is a palindrome.
#include <stdio.h>
#include <string.h>

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

    int len = (int)strlen(str);
    int isPalindrome = 1;

    /* Compare characters from both ends moving toward the center */
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("Palindrome\n");
    else
        printf("Not palindrome\n");

    return 0;
}