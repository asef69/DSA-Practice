#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        v[i]=i+1;
    }
    vector<int>pre(n);
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+v[i];
    }
    cout<<pre[n-1]<<endl;
}