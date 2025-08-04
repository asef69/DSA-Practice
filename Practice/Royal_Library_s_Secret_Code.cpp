#include <bits/stdc++.h>
using namespace std;
long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
string getPermutation(int n, int k, string s) {
    vector<long long> fact(n, 1);
    for (int i = 2; i < n; ++i) {
        fact[i] = fact[i - 1] * i;
    }
    if (k > fact[n - 1]) {
        return "-1";
    }
    vector<char> chars(s.begin(), s.end());
    sort(chars.begin(), chars.end());
    k--;
    string result = "";
    for (int i = n - 1; i >= 0; --i) {
        long long block_size = fact[i];
        int idx = k / block_size;
        result += chars[idx];
        chars.erase(chars.begin() + idx);
        
        k %= block_size;
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << getPermutation(n, k, s) << endl;
    return 0;
}
