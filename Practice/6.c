#include <stdio.h>
#include <string.h>
#include <ctype.h>

void abbreviateNames(const char *input, char *output) {
    int i = 0, j = 0;
    int isNewWord = 1; // Flag to indicate the start of a new word
    int wordCount = 0; // Count the number of words in a name segment

    while (input[i] != '\0') {
        // Handle commas separating names
        if (input[i] == ',') {
            output[j++] = ','; // Copy the comma
            output[j++] = ' '; // Add a space after the comma
            i++;
            isNewWord = 1;     // Next segment starts a new name
            wordCount = 0;
            continue;
        }

        // Handle spaces within a name
        if (input[i] == ' ') {
            if (j > 0 && output[j - 1] != ' ') { // Avoid multiple spaces
                output[j++] = ' ';
            }
            isNewWord = 1; // Next word starts here
            i++;
            continue;
        }

        // Process letters
        if (isNewWord) {
            if (wordCount > 0) { // Abbreviate middle names
                output[j++] = input[i]; // First letter of the word
                output[j++] = '.';      // Add a period
            } else { // Preserve the first word and track the position
                output[j++] = input[i];
            }
            isNewWord = 0; // No longer the start of a new word
            wordCount++;
        } else if (wordCount == 1) {
            // Preserve last names completely
            output[j++] = input[i];
        }
        i++;
    }

    // Null-terminate the output string
    output[j] = '\0';
}

int main() {
    char input[201], output[201]; // Allow for larger inputs if needed
    printf("Enter names separated by commas: ");
    fgets(input, 201, stdin);

    // Remove newline character from input if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    abbreviateNames(input, output);
    printf("Output: %s\n", output);

    return 0;
}
