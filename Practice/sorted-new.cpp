#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        set<long int> s;
        for(int i=0;i<n;i++){
            long int x; cin>>x;
            s.insert(x);
        }
        for(auto i=s.begin();i!=s.end();i++){
            cout<<*i<<" ";
        }
        cout<<endl;
    }
}