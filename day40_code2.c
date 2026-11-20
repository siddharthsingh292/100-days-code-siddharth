//Print each character of a string on a new line.
#include <stdio.h>

int main() {
    char s[100000];

    printf("Enter a string: ");

    if (scanf("%99999[^\n]", s) != 1) {
        printf("No input given.\n");   // empty line or no input
        return 0;
    }

    printf("Characters on separate lines:\n");

    int i = 0;
    while (s[i] != '\0' && s[i] != '\r') {
        printf("%c\n", s[i]);
        i++;
    }

    return 0;
}