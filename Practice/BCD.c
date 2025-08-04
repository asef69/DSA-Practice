#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int main()
{
    char *str;
    str = (char *)malloc(100 * sizeof(char));
    assert(str != NULL);
    scanf("%s", str);
    int i = 0;
    int k = 0;
    int *temp;
    temp = (int *)malloc(100 * sizeof(int));
    assert(temp != NULL);
    while (*(str + i) != '\0')
    {

        int s = 0;
        int m = 3;
        for (int j = i; j < i + 4; j++)
        {

            int a = (int)*(str + j) - '0';

            s += (a * pow(2, m));
            m--;
        }
        *(temp + k) = s;
        k++;
        i += 4;
    }

    for (int l = 0; l < k; l++)
    {
        printf("%d", *(temp + l));
    }

    free(temp);

    free(str);
}
