#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
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
        vector<long long> suffixSum(n+1, 0);
        for(int i=n-1;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + a[i];
        }
        long long minSum = LLONG_MAX;
        int minIndex = 0;

        for (int i = 1; i <= n; ++i) {
            long long currentSum = prefixSum[i] + suffixSum[i - 1];
            if (currentSum < minSum) {
                minSum = currentSum;
                minIndex = i;
            }
        }

        cout << minIndex << endl;
    }
}