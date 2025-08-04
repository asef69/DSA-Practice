#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> v(n);
    int sum=0,leftsum=0,rightsum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    for(int i=0;i<n;i++){
        rightsum=sum-leftsum-v[i];
        if(rightsum==leftsum) {
            cout<<i<<endl;
            return 0;
        }
        leftsum+=v[i];
    }

}