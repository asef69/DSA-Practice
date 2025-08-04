#include<stdio.h>
#include<stdlib.h>
char *strrchr(char *str, char ch) {
    char *last = NULL;
    while (*str) {
        if (*str == ch) last = str;
        str++;
    }
    return last;
}

int main() {
    char *str = "Hello, World!";
    char ch = 'o';

    char *result = strrchr(str, ch);
    if (result) printf("Last occurrence: %c\n", *result);
    else printf("Character not found.\n");

    return 0;
}
