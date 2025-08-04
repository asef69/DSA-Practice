#include<stdio.h>
#include<string.h>


int countOccurrences(char *sentence, char *word) {
    int i = 0, j = 0, count = 0;
    int wordStart;

    while (sentence[i] != '\0') {
        // Check if the current character matches the first character of the word
        if (sentence[i] == word[0]) {
            wordStart = i;
            j = 0;

            // Check the entire word
            while (word[j] != '\0' && sentence[wordStart] == word[j]) {
                wordStart++;
                j++;
            }

            // If the word was fully matched, and it is a standalone word
            if (word[j] == '\0' && 
                (i == 0 || sentence[i - 1] == ' ') && // Ensure the word is preceded by space or start of sentence
                (sentence[wordStart] == '\0' || sentence[wordStart] == ' ')) { // Ensure it's followed by space or end of sentence
                count++;
            }
        }
        i++;
    }

    return count;
}

int main() {
    char sentence[256], word[50];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    sentence[strcspn(sentence, "\n")] = '\0'; // Remove trailing newline

    printf("Enter a word: ");
    scanf("%s", word);

    int occurrences = countOccurrences(sentence, word);
    printf("The word '%s' occurs %d time(s).\n", word, occurrences);

    return 0;
}
