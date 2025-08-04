#include<stdio.h>
#include<stdlib.h>
int strend(char *s, char *t) {
    char *s_start = s, *t_start = t;
    while (*s) s++;
    while (*t) t++;

    while (t >= t_start && s >= s_start && *t == *s) {
        t--;
        s--;
    }

    return (t < t_start) ? 1 : 0;
}

int main() {
    char *s = "programming";
    char *t = "ming";

    if (strend(s, t)) printf("String t is at the end of s.\n");
    else printf("String t is NOT at the end of s.\n");

    return 0;
}
