#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    int q; cin>>s>>q;
    vector<int>pre(s.size()+1,0);

    for(int i=1;i<=s.size();i++){
        if(s[i-1]=='a') pre[i]=pre[i-1]+1;
     else {
        pre[i] = pre[i-1];
    }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        //cout<<pre[r-1] - (l > 1 ? pre[l-2] : 0)<<endl;
        
        cout<<pre[r]-pre[l-1]<<endl;
    }
}