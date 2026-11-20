#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toTitleCase(char *s) {
    int newWord = 1;                      // 1 when the next letter starts a word

    for (int i = 0; s[i] != '\0'; i++) {
        if (isspace((unsigned char)s[i])) {
            newWord = 1;
        } else if (newWord) {
            s[i] = toupper((unsigned char)s[i]);
            newWord = 0;
        } else {
            s[i] = tolower((unsigned char)s[i]);
        }
    }
}

int main() {
    char str[10001];

    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline added by fgets
    str[strcspn(str, "\n")] = '\0';

    toTitleCase(str);
    printf("%s\n", str);

    return 0;
}