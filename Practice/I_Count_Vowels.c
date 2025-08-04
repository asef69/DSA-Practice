#include <stdio.h>
#include <ctype.h>  // For tolower function

// Recursive function to count vowels in the string
int countVowels(char *str, int index) {
    // Base case: end of string
    if (str[index] == '\0') {
        return 0;
    }
    
    // Check if current character is a vowel
    char ch = tolower(str[index]);
    int isVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ? 1 : 0;
    
    // Recursively count vowels in the rest of the string
    return isVowel + countVowels(str, index + 1);
}

int main() {
    char str[201];
    fgets(str, 201, stdin); // Read the input string (including spaces)
    
    int vowelCount = countVowels(str, 0);
    printf("%d\n", vowelCount);
    
    return 0;
}
