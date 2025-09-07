#include<bits/stdc++.h>
using namespace std;

unordered_map<long long, bool> dp;

bool canReach(long long current, long long N) {
    if (current == N) return true;
    if (current > N) return false;
    if (dp.find(current) != dp.end()) return dp[current];
    bool result = canReach(current * 10, N) || canReach(current * 20, N);
    dp[current] = result;
    return result;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        dp.clear();
        if (canReach(1, n)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}