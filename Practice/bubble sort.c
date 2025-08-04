#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *items, int n, int *comp) {
    *comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (*(items + j) > *(items + j + 1)) {
                int temp = *(items + j);
                *(items + j) = *(items + j + 1);
                *(items + j + 1) = temp;
            }
        }
    }
}

int main() {
    int n = 5, comp;
    int *items = (int *)malloc(n * sizeof(int));
    *(items + 0) = 5; *(items + 1) = 3; *(items + 2) = 2;
    *(items + 3) = 4; *(items + 4) = 1;

    bubbleSort(items, n, &comp);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", *(items + i));
    printf("\nComparisons: %d\n", comp);

    free(items);
    return 0;
}
