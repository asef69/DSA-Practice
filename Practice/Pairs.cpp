#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, set<int, greater<int>>> m;
    for (int i = 0; i < n; i++) {
        string x;
        int a;
        cin >> x >> a;
        m[x].insert(a); 
    }

    for (const auto& entry : m) {
        const string& key = entry.first;
        const set<int, greater<int>>& values = entry.second;
        for (int val : values) {
            cout << key << " " << val << endl;
        }
    }

    return 0;
}
