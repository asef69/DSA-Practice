#include <bits/stdc++.h>
#define ll long long int
using namespace std;

// Make the check function to check if we can make T
// products in time <= mid
bool check(ll mid, ll N, ll T, ll* K)
{
    // Variable to count the number of products made
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += (mid / K[i]);
        if (sum >= T)
            return true;
    }
    return false;
}

// Function to find the minimum time to make T products
ll solve(ll N, ll T, ll* K)
{
    // Define the range in which our answer can lie
    ll low = 1, high = (*min_element(K, K + N)) * T ;
    ll ans;

    // Binary Search for the minimum time to make T products
    while (low <= high) {
        ll mid = (low + high) / 2;

        // Check if we can make T products in time <= mid
        if (check(mid, N, T, K)) {
            // Update the answer and reduce search space by
            // moving high to mid - 1
            ans = mid;
            high = mid - 1;
        }
        else {
            // Reduce the search space by moving low to mid
            // + 1
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    ll N,T; cin>>N>>T;
    vector<long long> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    cout << solve(N, T, v.data());
}
