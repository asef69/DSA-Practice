#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        minHeap.push(num);
    }

    int q;
    cin >> q;

    while (q--) {
        int command;
        cin >> command;

        if (command == 0) {
            int x;
            cin >> x;
            minHeap.push(x);
            cout << minHeap.top() << endl;
        } else if (command == 1) {
            if (minHeap.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << minHeap.top() << endl;
            }
        } else if (command == 2) {
            if (minHeap.empty()) {
                cout << "Empty" << endl;
            } else {
                minHeap.pop();
                if (minHeap.empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << minHeap.top() << endl;
                }
            }
        }
    }

    return 0;
}
