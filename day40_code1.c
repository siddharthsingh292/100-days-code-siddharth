//Count characters in a string without using built-in length functions.

#include <stdio.h>

int main() {
    char s[100000];

    printf("Enter a string: ");

    if (scanf("%99999[^\n]", s) != 1) {
        printf("Number of characters: 0\n");   // empty line or no input
        return 0;
    }

    int count = 0;
    while (s[count] != '\0' && s[count] != '\r') {
        count++;
    }

    printf("Number of characters: %d\n", count);
    return 0;
}