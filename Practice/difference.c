#include<stdio.h>
int main(){
    int a,b; scanf("%d %d",&a,&b);
    int *c=&a, *d=&b;
    int *diff;
    if(*c>*d){
        *diff=*c-*d;
    }
    else *diff=*d-*c;
    printf("%d",*diff);
}