#include <stdio.h>
#include <stdlib.h> // For generating random values
#include <time.h>

// Task 1: User-built string length function
int length(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

// Task 2: User-built string comparison function
int compare(char str1[], char str2[])
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
        {
            return 0; // Characters mismatch
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0'; // True if both end at the same position
}

// Task 3: Copy string
void copy(char change[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        change[i] = src[i];
        i++;
    }
    change[i] = '\0'; // Proper termination
}

// Task 4: Substring generator
void sub(char substitute[], char str[], int start, int len)
{
    for (int i = 0; i < len; i++)
    {
        substitute[i] = str[start + i];
    }
    substitute[len] = '\0'; // Terminate the string
}

// Custom strstr implementation
int strstr_custom(char haystack[], char needle[])
{
    int haystack_len = length(haystack);
    int needle_len = length(needle);

    if (needle_len == 0)
    {
        return 1; // Empty substring is always found
    }

    for (int i = 0; i <= haystack_len - needle_len; i++)
    {
        int found = 1;
        for (int j = 0; j < needle_len; j++)
        {
            if (haystack[i + j] != needle[j])
            {
                found = 0;
                break;
            }
        }
        if (found)
        {
            return 1; // Substring found
        }
    }

    return 0; // Substring not found
}

// Random word generator
void random_word(char result[], char arr[][30], int size)
{
    int index = rand() % size;
    copy(result, arr[index]);
}

// Word scrambler
void scramble(char input[])
{
    int strlength = length(input);
    for (int i = 0; i < strlength; i++)
    {
        int random_index = rand() % strlength;
        char temp = input[i];
        input[i] = input[random_index];
        input[random_index] = temp;
    }
}

// Caesar cipher encryption
void caesar_encrypt(char word[], int shift)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] = (word[i] - 'a' + shift) % 26 + 'a';
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] = (word[i] - 'A' + shift) % 26 + 'A';
        }
    }
}

// Global variables
int score = 0;
int utility = 0; // To ensure utility is used only once

// Display menu
void menu()
{
    printf("Welcome to the Game World!\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

// Anagram game
void anagram_game()
{
    char scramble_word[30], scrambled[30];
    random_word(scramble_word, (char[][30]){"listen", "earth", "binary"}, 3);
    copy(scrambled, scramble_word);
    scramble(scrambled);

    printf("\nStarting Anagram Challenge...\n");
    printf("Scrambled word: %s\n", scrambled);

    char try[30];
    for (int attempt = 0; attempt < 3; attempt++)
    {
        printf("Your guess: ");
        fgets(try, sizeof(try), stdin);
        try[length(try) - 1] = '\0'; // Remove newline

        if (compare(try, scramble_word))
        {
            printf("Correct! You solved it in %d attempt(s).\n", attempt + 1);
            score += 10 * (3 - attempt);
            return;
        }
        else
        {
            printf("Incorrect! Try again.\n");
        }
    }
    printf("The correct answer: %s\n", scramble_word);
}

// Caesar cipher game
void caesar_game()
{
    char game_phrase[30], encryption[30];
    random_word(game_phrase, (char[][30]){"There is a secret code", "Attack at dawn", "Meet me at the park"}, 3);
    copy(encryption, game_phrase);

    int shift = rand() % 25 + 1;
    caesar_encrypt(encryption, shift);

    printf("\nStarting Caesar Cipher Challenge...\n");
    printf("Encrypted phrase: %s\n", encryption);

    char try[30];
    for (int attempt = 0; attempt < 3; attempt++)
    {
        printf("Your guess: ");
        fgets(try, sizeof(try), stdin);
        try[length(try) - 1] = '\0'; // Remove newline

        if (compare(try, game_phrase))
        {
            printf("Correct! You decrypted it in %d attempt(s).\n", attempt + 1);
            score += 10 * (3 - attempt);
            return;
        }
        else
        {
            printf("Incorrect! Try again.\n");
        }
    }
    printf("The correct answer: %s\n", game_phrase);
}

// Guessing game
void guessing_game()
{
    char word[30], hint[10];
    random_word(word, (char[][30]){"program", "network", "science"}, 3);
    sub(hint, word, 0, 3);
    printf("\nStarting Word Guessing Challenge...\n");
    printf("Hint: %s______\n", hint);

    char guess[30];
    int attempt = 0;

    while (attempt < 3)
    {
        printf("Select an option:\n1. Write Answer\n2. Check Substring\n3. Check Length\n");
        int option;
        scanf("%d", &option);
        getchar(); // Handle leftover newline

        if (option == 1)
        {
            printf("Enter your guess: ");
            fgets(guess, sizeof(guess), stdin);
            guess[length(guess) - 1] = '\0';

            if (compare(guess, word))
            {
                printf("Correct! You guessed it in %d attempt(s).\n", attempt + 1);
                score += 10;
                return;
            }
            else
            {
                printf("Incorrect! Try again.\n");
            }
            attempt++;
        }
        else if (option == 2 && utility == 0)
        {
            char substring[30];
            printf("Enter substring: ");
            fgets(substring, sizeof(substring), stdin);
            substring[length(substring) - 1] = '\0';

            if (strstr_custom(word, substring))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            utility = 1;
            score -= 2;
        }
        else if (option == 3 && utility == 0)
        {
            int len;
            printf("Enter length: ");
            scanf("%d", &len);

            if (len == length(word))
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            utility = 1;
            score -= 2;
        }
        else
        {
            printf("Error: Utility function already used or invalid option\n");
        }
    }
    printf("The correct word: %s\n", word);
}

// Main function
int main()
{
    srand(time(NULL));
    while (1)
    {
        menu();
        int choice;
        scanf("%d", &choice);
        getchar(); // Handle leftover newline

        if (choice == 1)
        {
            score = 0;
            utility = 0;
            anagram_game();
            caesar_game();
            guessing_game();
            printf("\nGame Over! Your total score: %d points\n", score);
            break;
        }
        else if (choice == 2)
        {
            printf("Exiting game...\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    }
    return 0;
}
