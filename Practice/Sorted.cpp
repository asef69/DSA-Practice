#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        bool flag=1;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        for (int i = 1; i <n; i++)
        if (v[i - 1] > v[i]) flag=0;
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}




