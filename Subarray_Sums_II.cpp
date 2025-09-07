#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    vector<long long int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<long long int>pre(n+1);
    pre[0]=0;
    for(long long int i=1;i<=n;i++){
        pre[i]=pre[i-1]+v[i-1];
    }
    long long int result=0;
    vector<long long int>a(pre.begin()+1,pre.end());
    for(long long int i=1;i<=n;i++){
        for(long long int j=i;j<=n;j++){
            if(pre[j]-pre[i-1]==x) result++;
        }
    }
    cout<<result<<endl;
}