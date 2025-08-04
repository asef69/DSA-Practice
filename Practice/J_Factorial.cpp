#include<bits/stdc++.h>
using namespace std;
long long int dp[1005];
long long int fact(long long int n){
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=n*fact(n-1);
    return dp[n];
}
int main(){
    memset(dp,-1,sizeof(dp));
    long long int n;
    cin>>n;
    cout<<fact(n);
}