#include<bits/stdc++.h>
using namespace std;
long long fibo(int n){
    long long int result[n+1];
    result[0]=0;
    result[1]=1;
    result[2]=1;
    result[3]=2;
    for(int i=4;i<=n;i++){
    result[i]=result[i-1]+result[i-2]+result[i-3]+result[i-4];
    }
    return result[n];
}
int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
}