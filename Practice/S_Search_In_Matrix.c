#include<stdio.h>
#include<stdbool.h>
int main(){
    int n,m; scanf("%d %d",&n,&m);
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int flag=1;
    int x; scanf("%d",&x);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(x==a[i][j]){
                printf("will not take number");
                return 0;
            }
            else flag=0;
        }
    }
    if(!flag) printf("will take number");
}