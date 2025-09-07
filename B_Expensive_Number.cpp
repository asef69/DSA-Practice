#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;
        int len = n.size();
        if (len == 1) {
            cout << 0 << '\n';
            continue;
        }
        // Check if there's any digit '1' in the string
        bool has_one = false;
        for (char c : n) {
            if (c == '1') {
                has_one = true;
                break;
            }
        }
        if (has_one) {
            // We can keep one '1' and remove others, but need to check if there's another '1' later
            // The minimal deletion is len - 1 (keep one digit)
            // But if there are multiple '1's, we can keep any one
            cout << (len - 1) << '\n';
        } else {
            // All digits are >=2, the minimal cost is achieved by any single digit (cost = digit/digit = 1)
            cout << (len - 1) << '\n';
        }
    }
    return 0;
}