#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v(n);
    vector<int> pre(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    pre[0]=v[0];
   for(int i=1;i<n;i++){
    pre[i]=pre[i-1]+v[i];
   } 
    for(int i=0;i<n;i++){
        cout<<pre[i]<<" ";
    }
}