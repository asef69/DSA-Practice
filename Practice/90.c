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
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int temp=*(*(a+i)+j);
            *(*(a+j)+i)=*(*(a+i)+j);;
            *(*(a+i)+j)=temp;
        }
    }
    for(int i=0;i<n;i++){
            int j=0,k=n-1;
        while(j<k){
            int temp=*(*(a+i)+j);
            *(*(a+i)+j)=*(*(a+i)+k);;
            *(*(a+i)+k)=temp;
    j++,k--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(a+j)+i));
        }
        printf("\n");
    }


}
