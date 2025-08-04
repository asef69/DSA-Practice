#include<stdio.h>
void factorial(int* n, int* result){
    int factor=1;
    for(int i=1;i<=*n;i++){
        factor*=i;
    }
    printf("%d",factor);
}
int main(){
    int n; scanf("%d",&n);
    int result;
    factorial(&n,&result);
}
