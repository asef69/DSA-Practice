#include <stdio.h>
#include <string.h>

void extractSubstring(const char *str, int position, int length, char *result) {
    int strLength = strlen(str);
    if (position < 0 || position >= strLength) {
        strcpy(result, ""); 
        return;
    }

    if (length == 0) {
        
        strcpy(result, str + position);
    } else {

        strncpy(result, str + position-1, length);
        result[length] = '\0'; 
    }
}

int main() {
    char str[] = "Working with strings is fun";
    int position = 4;
    int length = 4;
    char result[100];

    extractSubstring(str, position, length, result);

    printf("substring: \"%s\"\n", result);

    return 0;
}
