#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    vector<int>c(2*n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<2*n;i++){
        if(i<n) c[i]=b[i];
        else c[i]=a[i-n];
    }
    for(int i=0;i<2*n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;
}