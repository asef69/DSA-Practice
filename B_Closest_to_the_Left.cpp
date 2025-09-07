#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMaxIndex(const vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1, result = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            result = mid + 1; // Store 1-based index
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    cin >> n >> k; // Number of array elements and queries

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    vector<int> queries(k);
    for (int i = 0; i < k; ++i) {
        cin >> queries[i];
    }

    for (int i = 0; i < k; ++i) {
        cout << findMaxIndex(arr, queries[i]) << endl;
    }

    return 0;
}
