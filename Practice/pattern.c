#include<stdio.h>
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=7;j++){
            if(j==4) printf("*");
            if(i<4 && (i==j ||i+j==8)) printf("*");
            if(i>=4 && (i+j==6)) printf("*");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
