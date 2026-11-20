#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(const char *s) {
    int lastSeen[256];          // last index where each character appeared
    int start = 0;              // start of current window
    int maxLen = 0;
    int n = strlen(s);

    for (int i = 0; i < 256; i++)
        lastSeen[i] = -1;

    for (int i = 0; i < n; i++) {
        unsigned char c = s[i];

        // If c was seen inside the current window, move the window start
        if (lastSeen[c] >= start)
            start = lastSeen[c] + 1;

        lastSeen[c] = i;

        int len = i - start + 1;
        if (len > maxLen)
            maxLen = len;
    }
    return maxLen;
}

int main() {
    char s[100001];

    printf("Enter the string: ");
    fgets(s, sizeof(s), stdin);

    // Remove trailing newline added by fgets
    s[strcspn(s, "\n")] = '\0';

    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}