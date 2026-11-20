#include <stdio.h>
#include <string.h>

int main() {
    char text[1001];

    FILE *fp = fopen("data.txt", "a");
    if (fp == NULL) {
        printf("Error: could not open data.txt\n");
        return 1;
    }

    printf("Enter the text to append: ");
    fgets(text, sizeof(text), stdin);

    // Remove trailing newline added by fgets
    text[strcspn(text, "\n")] = '\0';

    fprintf(fp, "%s\n", text);

    fclose(fp);

    printf("File updated successfully with appended text.\n");
    return 0;
}