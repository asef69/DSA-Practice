#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,k ; cin>>n>>k;
        vector<int>v(n+1,0);
        for(int i=1;i<=n;i++){
            int x; cin>>x;
            v[i]=v[i-1]+x;
        }
        while(k--){
            int l,r,k; cin>>l>>r>>k;
            long long int range=v[r]-v[l-1];
            long long int current=v[n]-range+(r-l+1)*k;
            if(current%2==0) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
}