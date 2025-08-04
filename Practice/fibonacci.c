#include<stdio.h>
int main(){
    int n; scanf("%d",&n);
    int first=0,second=1,nextterm;
     printf("%d %d ",first,second);
    for(int i=0;i<n;i++){
        nextterm=second+first;
        first=second;
        second=nextterm;
         printf("%d ",nextterm);

    }
}