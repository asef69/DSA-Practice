#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<long long> prefixSum(n+1, 0);
    for(int i=1;i<=n;i++){
        prefixSum[i] = prefixSum[i-1] + a[i-1];
    }
    int m;
    cin>>m;
    vector<long long> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        long long sum = b[i];
        int low = 0;
        int high = n;
        while(low<high){
            int mid = low + (high-low)/2;
            if(prefixSum[mid]<sum){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        cout<<low<<endl;
    }
}