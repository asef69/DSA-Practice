#include <stdio.h>

void separateEvenOdd(int arr[], int size)
{
    int even[100], odd[100];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even[evenCount++] = arr[i];
        }
        else
        {
            odd[oddCount++] = arr[i];
        }
    }

    printf("even: {");
    for (int i = 0; i < evenCount; i++)
    {
        printf("%d", even[i]);
        if (i < evenCount - 1)
        {
            printf(",");
        }
    }
    printf("}\n");

    printf("odd: {");
    for (int i = 0; i < oddCount; i++)
    {
        printf("%d", odd[i]);
        if (i < oddCount - 1)
        {
            printf(",");
        }
    }
    printf("}\n");
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    separateEvenOdd(arr, size);

    return 0;
}
