#include <stdio.h>
#include <string.h>

// Function to find the position of the rightmost occurrence of t in s
int strindex(const char *s, const char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    
    // If t is longer than s, it can't be found
    if (len_t > len_s) {
        return -1;
    }

    // Traverse the string s from the end
    for (int i = len_s - len_t; i >= 0; i--) {
        // Check if substring starting at s[i] matches t
        int j = 0;
        while (j < len_t && s[i + j] == t[j]) {
            j++;
        }

        // If we matched the entire string t, return the current index
        if (j == len_t) {
            return i;
        }
    }

    // If no match is found, return -1
    return -1;
}

int main() {
    char s[1000], t[100];

    // Take user input for s and t
    printf("Enter string s: ");
    fgets(s, sizeof(s), stdin);
    printf("Enter string t: ");
    fgets(t, sizeof(t), stdin);

    // Remove newline characters if present (from fgets)
    s[strcspn(s, "\n")] = '\0';
    t[strcspn(t, "\n")] = '\0';

    // Call strindex function and output the result
    int result = strindex(s, t);
    printf("The rightmost occurrence of '%s' in '%s' is at index: %d\n", t, s, result);

    return 0;
}
