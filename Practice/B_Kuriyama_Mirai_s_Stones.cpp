#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> v(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        long long cost;
        cin >> cost;
        v[i] = v[i - 1] + cost;
    }

    vector<long long> sorted_v(n + 1, 0);
    vector<long long> stones(n);

    for (int i = 0; i < n; ++i) {
        stones[i] = v[i + 1] - v[i];
    }

    sort(stones.begin(), stones.end());

    for (int i = 1; i <= n; ++i) {
        sorted_v[i] = sorted_v[i - 1] + stones[i - 1];
    }

    int m;
    cin >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            cout << v[r] - v[l - 1] << endl;
        } else {
            cout << sorted_v[r] - sorted_v[l - 1] << endl;
        }
    }

    return 0;
}
