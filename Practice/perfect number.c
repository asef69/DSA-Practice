#include<stdio.h>
int main(){
    int n,sum=0,digits=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(n%i==0) {sum+=i;
        digits++;
        }
    }
    if(n==sum) printf("%d is a perfect number",n);
    else {
        printf("Not Perfect");
    }
}