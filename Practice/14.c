#include <stdio.h>
#include <string.h>

// Function to check if t occurs at the end of s
int strend(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // If t is longer than s, it cannot be at the end of s
    if (len_t > len_s) {
        return 0;
    }

    // Compare the end of s with t
    for (int i = 0; i < len_t; i++) {
        if (s[len_s - len_t + i] != t[i]) {
            return 0;  // Mismatch, return 0
        }
    }

    return 1;  // Match, return 1
}

int main() {
    char s[1000], t[100];

    // Input the strings
    printf("Enter string s: ");
    fgets(s, sizeof(s), stdin);
    printf("Enter string t: ");
    fgets(t, sizeof(t), stdin);

    // Remove newline character from the input strings (if any)
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    // Call strend function and output the result
    if (strend(s, t)) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
