#include <stdio.h>

int countjump(int a[], int n)
{
    int d=n-1;
    int count=0,i=0;

    while(i<d)
    {
        if(n==1)
        {
            return 0;
        }
        if(a[i]==0)
        {
             return -1;
        }
        if((i+a[i])>=(n-1))
        {
            count++;
            break;
        }

        i+=a[i];
        count++;

    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i=0; i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    int result = countjump(a,n);
    printf("%d", result);
    return 0;
}
