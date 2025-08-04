#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<string> q;
    string command, name;
    
    while (n--) {
        cin >> command;
        
        if (command == "0") {
            cin >> name;
            q.push(name);
        } else if (command == "1") {
            if (q.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }

    return 0;
}
