#include<stdio.h>
void merge(int *arr1, int n1, int *arr2, int n2, int *out) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (*(arr1 + i) <= *(arr2 + j)) {
            *(out + k++) = *(arr1 + i++);
        } else {
            *(out + k++) = *(arr2 + j++);
        }
    }
    while (i < n1) *(out + k++) = *(arr1 + i++);
    while (j < n2) *(out + k++) = *(arr2 + j++);
}

int main() {
    int n1 = 3, n2 = 4;
    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n2 * sizeof(int));
    int *out = (int *)malloc((n1 + n2) * sizeof(int));

    *(arr1 + 0) = 1; *(arr1 + 1) = 3; *(arr1 + 2) = 5;
    *(arr2 + 0) = 2; *(arr2 + 1) = 4; *(arr2 + 2) = 6; *(arr2 + 3) = 8;

    merge(arr1, n1, arr2, n2, out);

    printf("Merged array: ");
    for (int i = 0; i < n1 + n2; i++) printf("%d ", *(out + i));
    printf("\n");

    free(arr1); free(arr2); free(out);
    return 0;
}
