#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string str;
        cin >> str;
        
        stack<char> s;
        bool isValid = true;
        
        for (char c : str) {
            if (c == '0') {
                if (!s.empty() && s.top() == '1') {
                    s.pop();
                } else {
                    s.push(c);
                }
            } else if (c == '1') {
                if (!s.empty() && s.top() == '0') {
                    s.pop();
                } else {
                    s.push(c);
                }
            }
        }
        
        if (s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
