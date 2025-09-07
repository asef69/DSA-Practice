#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Group consecutive sushi into segments
    vector<pair<int, int>> segments; // {type, count}
    int currentType = a[0], currentCount = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == currentType) {
            currentCount++;
        } else {
            segments.push_back({currentType, currentCount});
            currentType = a[i];
            currentCount = 1;
        }
    }
    segments.push_back({currentType, currentCount});

    // Find the maximum valid subsegment length
    int maxLen = 0;
    for (int i = 1; i < segments.size(); i++) {
        int len = 2 * min(segments[i - 1].second, segments[i].second);
        maxLen = max(maxLen, len);
    }

    cout << maxLen << endl;
    return 0;
}
