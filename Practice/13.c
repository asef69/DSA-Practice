#include <stdio.h>
#include <ctype.h>  // For tolower function

#define MAX_LEN 1000  // Maximum length of the input string

int main() {
    char str[MAX_LEN];
    int freq[26] = {0};  // Array to store frequency of each alphabet (26 letters)

    // Input the string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Traverse through the string
    for (int i = 0; str[i] != '\0'; i++) {
        // Convert character to lowercase and check if it's a letter
        if (isalpha(str[i])) {
            char ch = tolower(str[i]);  // Convert to lowercase
            freq[ch - 'a']++;  // Increment the count for the character
        }
    }

    // Output the frequency of each alphabet
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c:%d", i + 'a', freq[i]);
            if (i < 25) {
                printf(", ");  // Add comma between results
            }
        }
    }
    printf("\n");

    return 0;
}
