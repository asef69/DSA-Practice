#include<stdio.h>
int maximum(int *a,int n){
    int ma=a[0];
    for(int i=0;i<n;i++){
        if(a[i]>ma) ma=a[i];
    }
    printf("%d",ma);
}
int minimum(int *a,int n){
    int ma=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<ma) ma=a[i];
    }
    printf("%d ",ma);
}
int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int minim=minimum(a,n);
    int maxi=maximum(a,n);
    
}