#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;

        // Place a monkeys in row 1
        long long row1 = min(a, m);

        // Place b monkeys in row 2
        long long row2 = min(b, m);

        // Remaining seats in each row after placing a and b
        long long remaining_row1 = m - row1;
        long long remaining_row2 = m - row2;

        // Distribute the c monkeys in the remaining seats
        long long distributed_c = min(c, remaining_row1 + remaining_row2);

        // Total seated monkeys
        long long total_seated = row1 + row2 + distributed_c;

        cout << total_seated << endl;
    }

    return 0;
}
