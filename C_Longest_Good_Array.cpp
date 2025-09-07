#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,count=0; cin>>t;
    while(t--){
        int l,r; cin>>l>>r;
        long long left = l;
    long long sum = 0;
    long long k = 1;
    while (left <= r) {
        sum += k; 
        if (left + sum > r) {
            break;
        }
        k++;
    }
    
    cout << k << endl;
    }
}