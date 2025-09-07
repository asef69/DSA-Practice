#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int m; cin>>m;
    vector<int>a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    int q; cin>>q;
    v.insert(v.begin()+q,a.begin(),a.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}