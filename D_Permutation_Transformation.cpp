#include<bits/stdc++.h>
using namespace std;
void buildTree(vector<int>& v,int left, int right, int depth,vector<int>& depths){
    if(left>right) return;
    int max_pos=left;
    for(int i=left+1;i<=right;i++){
        if(v[i]>v[max_pos]) max_pos=i;
    }
    depths[max_pos]=depth;
    buildTree(v,left,max_pos-1,depth+1,depths);
    buildTree(v,max_pos+1,right,depth+1,depths);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<int> depth(n,0);
        buildTree(v,0,n-1,0,depth);
        for(int i=0;i<n;i++){
            cout<<depth[i]<<" ";
        }
        cout<<endl;
    }
}