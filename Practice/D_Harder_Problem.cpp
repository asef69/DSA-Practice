#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(n);
        vector<int> freq(n + 1, 0);
        int mode = a[0], max_freq = 0;

        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
            if (freq[a[i]] > max_freq || (freq[a[i]] == max_freq && a[i] < mode)) {
                max_freq = freq[a[i]];
                mode = a[i];
            }
            b[i] = mode;
        }

        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    solve();
    return 0;
}
