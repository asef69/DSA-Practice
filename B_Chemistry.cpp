#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    int m = n - k;
    if (m == 0) {
        return "YES"; 
    }
    
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }
    
    int odd_counts = 0;
    for (int count : freq) {
        if (count % 2 != 0) {
            odd_counts++;
        }
    }
    
    if (odd_counts <= 1) {
        if (m % 2 == 1) {
            return "YES";
        } else {
            if (odd_counts == 0) {
                return "YES";
            } else {
                return "NO";
            }
        }
    } else {
        int needed_reductions = odd_counts - 1;
        if (k >= needed_reductions && (m % 2 == 1 || (k - needed_reductions) % 2 == 0)) {
            return "YES";
        } else {
            return "NO";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    
    return 0;
}