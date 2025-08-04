#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    vector<int> stackValues(n);
    vector<int> queueValues(m);

    for (int i = 0; i < n; ++i) {
        cin >> stackValues[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> queueValues[i];
    }

    stack<int> st;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        st.push(stackValues[i]);
    }

    for (int i = 0; i < m; ++i) {
        q.push(queueValues[i]);
    }

    bool isSame = true;
    for (int i = 0; i < n; ++i) {
        int stackTop = st.top();
        st.pop();

        int queueFront = q.front();
        q.pop();

        if (stackTop != queueFront) {
            isSame = false;
            break;
        }
    }

    if (isSame) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
