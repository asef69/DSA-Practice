#include<stdio.h>
#include<stdlib.h>
void maxCommSubArray(int *arr1, int n1, int *arr2, int n2, int *out, int *n3) {
    int max_len = 0, end_idx = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int len = 0;
            while (i + len < n1 && j + len < n2 && *(arr1 + i + len) == *(arr2 + j + len)) {
                len++;
            }
            if (len > max_len) {
                max_len = len;
                end_idx = i + len;
            }
        }
    }

    *n3 = max_len;
    for (int i = 0; i < max_len; i++) {
        *(out + i) = *(arr1 + end_idx - max_len + i);
    }
}

int main() {
    int n1 = 6, n2 = 5, n3;
    int *arr1 = (int *)malloc(n1 * sizeof(int));
    int *arr2 = (int *)malloc(n2 * sizeof(int));
    int *out = (int *)malloc((n1 > n2 ? n1 : n2) * sizeof(int));

    int arr1_vals[] = {1, 2, 3, 2, 1, 5};
    int arr2_vals[] = {3, 2, 1, 5, 6};

    for (int i = 0; i < n1; i++) arr1[i] = arr1_vals[i];
    for (int i = 0; i < n2; i++) arr2[i] = arr2_vals[i];

    maxCommSubArray(arr1, n1, arr2, n2, out, &n3);

    printf("Maximum Common Subarray: ");
    for (int i = 0; i < n3; i++) printf("%d ", *(out + i));
    printf("\n");

    free(arr1); free(arr2); free(out);
    return 0;
}
