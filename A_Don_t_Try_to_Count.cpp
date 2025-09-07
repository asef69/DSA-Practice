#include <iostream>
#include <string>
using namespace std;

int solve() {
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;
    
    int operations = 0;
    while (x.size() < 100) { 
        if (x.find(s) != string::npos) {
            return operations;
        }
        x += x;
        operations++;
    }
    if (x.find(s) != string::npos) {
        return operations;
    }
    return -1;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    
    return 0;
}