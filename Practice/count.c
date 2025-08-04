#include<stdio.h>
int main(){
    int n,m,x; scanf("%d %d %d",&n,&m,&x);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    while(x--){
        int b; scanf("%d",&b);
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==b) count++;
        }
    }
    printf("%d\n",count);
    }
}