#include<stdio.h>
#include<stdlib.h>
void reverse(int *arr, int n) {
    int *start = arr, *end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

int main() {
    int n = 5;
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) *(arr + i) = i + 1;

    reverse(arr, n);

    printf("Reversed array: ");
    for (int i = 0; i < n; i++) printf("%d ", *(arr + i));
    printf("\n");

    free(arr);
    return 0;
}
