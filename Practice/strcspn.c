#include<stdio.h>
#include<stdlib.h>
int strcspn(char *src, char *search) {
    int len = 0;
    while (*src) {
        char *temp = search;
        while (*temp) {
            if (*src == *temp) return len;
            temp++;
        }
        src++;
        len++;
    }
    return len;
}

int main() {
    char *src = "abcdef";
    char *search = "dx";

    int len = strcspn(src, search);
    printf("Length of initial segment: %d\n", len);

    return 0;
}
