#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Helper function to check if "1100" exists around a specific index
bool contains1100(const string &s, int pos) {
    if (pos < 0 || pos + 3 >= s.size()) return false;
    return s.substr(pos, 4) == "1100";
}

int main() {
    

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;
        
        int n = s.size();
        bool has1100 = false;
        
        // Initial check for "1100" in the string
        for (int i = 0; i <= n - 4; ++i) {
            if (contains1100(s, i)) {
                has1100 = true;
                break;
            }
        }

        while (q--) {
            int i, v;
            cin >> i >> v;
            i--;  // Convert to 0-based index

            if (s[i] - '0' == v) {
                // No change in the character, so answer based on current `has1100`
                cout << (has1100 ? "YES" : "NO") << '\n';
                continue;
            }

            // Check affected positions around `i` before the change
            bool was1100 = false;
            for (int j = max(0, i - 3); j <= min(n - 4, i); ++j) {
                if (contains1100(s, j)) {
                    was1100 = true;
                    break;
                }
            }

            // Apply the change
            s[i] = '0' + v;

            // Check affected positions around `i` after the change
            bool now1100 = false;
            for (int j = max(0, i - 3); j <= min(n - 4, i); ++j) {
                if (contains1100(s, j)) {
                    now1100 = true;
                    break;
                }
            }

            // Update `has1100` based on the changes
            has1100 = (has1100 && !was1100) || now1100;
            cout << (has1100 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
