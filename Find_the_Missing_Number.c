#include<stdio.h>
int main(){
    int t; scanf("%d",&t);
    while(t--){
        long long m;
        int a,b,c; scanf("%lld %d %d %d",&m,&a,&b,&c);
        if(m==0) printf("0\n");
        else{
            if(m%(a*b*c)==0) printf("%lld\n",m/(a*b*c));
            else printf("-1\n");
        }
    }
}