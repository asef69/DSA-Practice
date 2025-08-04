#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        // Read only the last k prefix sums
        vector<long long> s(n + 1);
        for (int i = n - k + 1; i <= n; i++) {
            cin >> s[i];
        }
        
        // Special case: If k == 1, it's always valid
        if (k == 1) {
            cout << "YES" << endl;
            continue;  // Go to the next test case
        }
        
        // Prepare the vector 'a' to store the differences between prefix sums
        vector<long long> a(n + 1);
        for (int i = n - k + 2; i <= n; i++) {
            a[i] = s[i] - s[i - 1];
        }
        
        // Check if the last k differences are sorted
        
        if (!is_sorted(a.begin() + n - k + 2, a.end())) {
            cout << "NO" << endl;
            continue;
        }

        // Check the condition for the sequence to be valid
        if (s[n - k + 1] > a[n - k + 2] * (n - k + 1)) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
    }

    return 0;
}
