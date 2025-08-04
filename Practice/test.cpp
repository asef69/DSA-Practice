#include<stdio.h>
int main(){
   int nst=1;
   for(int i=1;i<=5;i++){
    for(int j=1;j<=5-i;j++){
        printf(" ");
    }
    for(int k=1;k<=nst;k++){
        printf("*");
    }
    nst+=2;
    printf("\n");
   }
}