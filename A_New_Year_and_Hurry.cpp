#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    int left=240-k;
    vector<int>v(n);
    vector<int>pre(n);
    for(int i=0;i<n;i++){
        v[i]=(i+1)*5;
    }
    pre[0]=v[0];
    for(int i=1;i<n;i++){
        pre[i]=pre[i-1]+v[i];
    }
    for(int i=0;i<n;i++){
        if(pre[i]>left){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<n<<endl;


}