#include <stdio.h>
#include <string.h>
void frequency(int a[], int size)
{
    int freq[1000] = {0};
    int maxFreq = 0;
    int mostFrequentElement = a[0];

    for (int i = 0; i < size; i++)
    {
        freq[a[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        if (freq[a[i]] != 0)
        {
            printf("%d : %d times\n", a[i], freq[a[i]]);
            if (freq[a[i]] > maxFreq)
            {
                maxFreq = freq[a[i]];
                mostFrequentElement = a[i];
            }
            freq[a[i]] = 0;
        }
    }

    printf("%d", mostFrequentElement);
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    frequency(a, n);
}