#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp = fopen("sample.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open sample.txt\n");
        return 1;
    }

    int ch;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;          // 1 while we are inside a word
    int lastChar = '\n';     // last character read, used to detect an unterminated last line

    while ((ch = fgetc(fp)) != EOF) {
        if (ch != '\n')
            chars++;         // count every character except the newline

        if (ch == '\n')
            lines++;

        if (isspace((unsigned char)ch)) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            words++;         // a new word starts here
        }

        lastChar = ch;
    }

    // If the file does not end with '\n', the last line was not counted yet
    if (lastChar != '\n')
        lines++;

    fclose(fp);

    printf("Characters: %d\n", chars);
    printf("Words: %d\n", words);
    printf("Lines: %d\n", lines);
    return 0;
}
