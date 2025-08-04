#include<stdio.h>
int main(){
    int a[10]={-1};
    int *head=&a[0];
    int i;
    head++;
    for(i=0;i<9;i++){
        *head++=head[-1]+2;
        printf("head[-1]=%d,a[%d]=%d\n",head[-1],i,a[i]);
    }
} 