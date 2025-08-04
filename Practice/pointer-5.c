#include<stdio.h>
int sum(int *a,int size){
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=*(a+i);
    }
    return sum;
}
int main(){
    int size; scanf("%d",&size);
    int *a=(int *)malloc(size*sizeof(int));
    for(int i=0;i<size;i++){
        scanf("%d",a+i);
    }
    int add=sum(a,size);
    printf("%d",add);
}
