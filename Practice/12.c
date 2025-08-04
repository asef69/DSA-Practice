#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000  // Define maximum length for input

int main() {
    char sentence[MAX_LEN];
    char *words[MAX_LEN];  // Array of pointers to words
    int wordCount = 0;

    // Input a line of text
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from the input
    sentence[strcspn(sentence, "\n")] = '\0';

    // Tokenize the sentence into words
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[wordCount++] = token;  // Store each word in the array
        token = strtok(NULL, " ");
    }

    // Print the words in reverse order
    printf("Reversed sentence: ");
    for (int i = wordCount - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");  // Add space between words
        }
    }
    printf("\n");

    return 0;
}
