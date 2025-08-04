#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[1000];
    bool exists[1002] = {0}; // To check if a number exists, with some extra space

    // Reading input and marking numbers in the "exists" array
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        exists[a[i]] = true;
    }

    int count = 0;

    // Counting elements for which ai + 1 exists
    for (int i = 0; i < n; ++i) {
        if (exists[a[i] + 1]) {
            ++count;
        }
    }

    cout << count << endl;
    return 0;
}
