#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    while(k--){
            int l=0,r=n-1;
            bool flag=0;
            int mid;
            int x; cin>>x;
            while(l<=r){
                mid = (l + r) / 2;
                if(v[mid] == x){
                    flag=1;
                    break;
                }
                else if(v[mid]>x){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
                if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
}