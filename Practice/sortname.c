#include <string.h>

void sortNames(char *names[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main() {
    int n = 3;
    char **names = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        names[i] = (char *)malloc(50 * sizeof(char));
    }

    strcpy(names[0], "Zoe");
    strcpy(names[1], "Alice");
    strcpy(names[2], "Bob");

    sortNames(names, n);

    printf("Sorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }
    free(names);

    return 0;
}
