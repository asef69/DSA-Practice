#include<stdio.h>
int main(){
    int n,digits=0; 
    while(n!=0){
        int a=n%10;
        digits++;
        n/=10;
    }
}