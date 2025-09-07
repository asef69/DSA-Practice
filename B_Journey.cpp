#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // Read the number of test cases
    while (t--) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;  // Read the values for n, a, b, and c
        
        long long cycle_distance = a + b + c;  // Total distance in one full cycle of 3 days
        long long full_cycles = n / cycle_distance;  // Number of full 3-day cycles
        
        // Calculate the total distance after completing full cycles
        long long total_distance = full_cycles * cycle_distance;
        
        // Now, check how many extra days are needed
        if (total_distance >= n) {
            // If after full cycles, we already walked enough, print the last day of that cycle
            cout << full_cycles * 3 << endl;
        } else {
            // Otherwise, we need to walk on extra days
            total_distance += a;
            if (total_distance >= n) {
                cout << full_cycles * 3 + 1 << endl;
            } else {
                total_distance += b;
                if (total_distance >= n) {
                    cout << full_cycles * 3 + 2 << endl;
                } else {
                    total_distance += c;
                    cout << full_cycles * 3 + 3 << endl;
                }
            }
        }
    }
    return 0;
}
