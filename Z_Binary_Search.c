#include<stdio.h>
int main(){
    int n,q; scanf("%d %d",&n,&q);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(q--){
        int x;
        for(int i=0;i<n;i++){
            if(x==a[i]) printf("found\n");
        }
        printf("not found\n");
    }
}