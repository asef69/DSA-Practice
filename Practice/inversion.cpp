#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& arr, int l, int m, int r) {
    vector<int> temp;
    int count = 0;
    int left = l;
    int right = m + 1;
    while (left <= m && right <= r) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
            count += m - left + 1;
        }
    }
    while (left <= m) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= r) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = l; i <= r; i++) {
        arr[i] = temp[i - l];
    }
    return count;
}

int mergesort(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int m = (l + r) / 2;
    int first = mergesort(arr, l, m);
    int second = mergesort(arr, m + 1, r);
    int final = merge(arr, l, m, r);
    return first + second + final;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> arr(n);  // Fixed: need to specify size when declaring vector
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (n < 2) {
            cout << "Invalid input" << endl;
            continue;
        }
        else {
            int count = mergesort(arr, 0, arr.size() - 1);
            cout << count << endl;
        }
    }
    return 0;
}