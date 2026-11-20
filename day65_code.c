#include <stdio.h>
#include <string.h>

int isAnagram(const char *s, const char *t) {
    int count[26] = {0};

    // Different lengths can never be anagrams
    if (strlen(s) != strlen(t))
        return 0;

    // Add for s, subtract for t
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }

    // If every count is back to 0, frequencies match
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0)
            return 0;
    }
    return 1;
}

int main() {
    char s[100001], t[100001];

    printf("Enter string s: ");
    scanf("%100000s", s);

    printf("Enter string t: ");
    scanf("%100000s", t);

    if (isAnagram(s, t))
        printf("Anagram\n");
    else
        printf("Not Anagram\n");

    return 0;
}