#include<stdio.h>
int main(){
    int n,f=0; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<min) min=a[i];
    }
    for(int i=0;i<n;i++){
        if(min==a[i]) f++;
    }
    if(f%2!=0) printf("Lucky");
    else printf("Unlucky");
}