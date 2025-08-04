#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int main(){
     int n; scanf("%d",&n);
    int **a=(int **)malloc(n*sizeof(int*));
    assert(*a!=NULL);
    for(int i=0;i<n;i++){
        *(a+i)=(int*)malloc(n*sizeof(int));
        assert(*(a+i)!=NULL);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",*(a+i)+j);
        }
    }
    int max=0,row;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<n;j++){
            sum+=*(*(a+i)+j);
        }
        if(max<sum){
            max=sum;
            row=i+1;
        }
    }
    printf("%d",row);
}
