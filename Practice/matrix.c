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
        for(int j=0;j<n;j++){
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
    int **b=(int **)malloc(n*sizeof(int*));
    assert(*b!=NULL);
    for(int i=0;i<n;i++){
        *(b+i)=(int*)malloc(n*sizeof(int));
        assert(*(b+i)!=NULL);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",*(b+i)+j);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(a+i)+j));
        }
        printf("\n");
    }
    int **c=(int **)malloc(n*sizeof(int*));
    assert(*c!=NULL);
    for(int i=0;i<n;i++){
        *(c+i)=(int*)malloc(n*sizeof(int));
        assert(*(c+i)!=NULL);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(*(c+i)+j)=(*(*(a+i)+j))+(*(*(b+i)+j));
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",*(*(c+i)+j));
        }
        printf("\n");
    }
    free(c);
    free(a);
    free(b);


}
