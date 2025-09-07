#include<stdio.h>
void shift(int *a,int n){
     int j = 0; // pointer to place non-zero elements
    
    // Move all non-zero elements to the front of the array
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            a[j++] = a[i];
        }
    }
    
    // Fill remaining positions with zeros
    while (j < n) {
        a[j++] = 0;
    }
}
int main(){
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    shift(a,n);
        for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
