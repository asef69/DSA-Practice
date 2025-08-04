#include<stdio.h>
#include<math.h>
int login(int n,int i){
    if(n==1) return 0;
    int sum=pow(2,i);
    if((sum == n)) return i; 
    login(n,i+1);
}
int main(){
    int n; scanf("%d",&n);
    printf("%d",login(n,0));
}