#include<stdio.h>
int main(){
    long int a,b,c,d;
    scanf("%li %li %li %li",&a,&b,&c,&d);
    if((a+b*c)==d) printf("YES");
    else if((a-b*c)==d) printf("YES");
    else if((a*b+c)==d) printf("YES");
    else if((a*b-c)==d) printf("YES");
    else printf("NO");
}