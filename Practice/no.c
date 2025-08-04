#include<stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n];
        int count[100001] = {0};
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        count[a[i]]++;
    }
    int new=0;

 int index=sizeof(count)/sizeof(count[0]);
    for (int i = 1; i <=index; i++) {
        if (count[i] == 1) {
            new++;
        }
    }
    printf("%d",new);
}