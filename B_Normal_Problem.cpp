#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        string a;
        cin >> a;
        string b = a; // Initialize b to have the same size as a

        // Correct the transformation logic
        for (size_t i = 0; i < a.length(); ++i) {
            b[i] = a[a.length() - i - 1]; // Reverse the character position
            if (b[i] == 'p') b[i] = 'q';
            else if (b[i] == 'q') b[i] = 'p';
            // 'w' remains 'w', no need to handle explicitly
        }

        cout << b << endl;
    }

    return 0;
}
