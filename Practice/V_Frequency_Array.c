#include<stdio.h>
int main(){
    int n,m; scanf("%d %d",&n,&m);
    int a[n];
    int h[100000]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        h[a[i]]++;
    }
    for(int i=0;i<100000;i++){
        if(i>=1 && i<=m)
        printf("%d\n",h[i]);
    }

}