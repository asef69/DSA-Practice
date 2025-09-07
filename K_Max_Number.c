#include<stdio.h>
int max(int *a,int n){
    if(n==1) return a[0];
    int maxi=max(a,n-1);
    return (a[n-1]>maxi)? a[n-1]:maxi;
}
int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d",max(a,n));
}