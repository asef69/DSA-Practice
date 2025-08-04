#include<stdio.h>
int main(){
    int n,reverse=0,orginal; scanf("%d",&n);
    orginal=n;
    while(n!=0){
        int remainder=n%10;
        reverse=reverse*10+remainder;
        n/=10;
    }
    if(orginal==reverse) printf("PALINDROME");
    else printf("NOT PALINDROME");
}