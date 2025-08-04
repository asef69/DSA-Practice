#include<stdio.h>
int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int highest=0,lowest=0;
    int max=a[0],min=a[0];
    int result[n];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        highest++;
        }
        if(a[i]<min){
            min=a[i];
            lowest++;
        }
    }
    printf("%d %d",highest,lowest);
    
}