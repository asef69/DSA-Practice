#include<stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int min=a[0],index=1;
    for(int i=1;i<n;i++){
        if(a[i]<min){
            min=a[i];
            index=i+1;
        }
    }
    printf("%d %d",min,index);
}
