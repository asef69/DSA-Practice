#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <limits>

using namespace std;

int countPairs(int k, int l1, int r1, int l2, int r2) {
    int count = 0;
    unordered_set<long long> validY;  // Use long long to store y values
    int n=0;
    // Iterate over x from l1 to r1 using a traditional for loop
    for (int x = l1; x <= r1; ++x) {
        long long y = x;  // Initialize y with x
        while (y <= r2) {
            if (y >= l2) {
                validY.insert(y); 
                n++;// Insert y into the set if it lies in [l2, r2]
            }
            if (y > r2 / k) break; // Prevent overflow in the next multiplication
            y *= k; // Update y to the next power of k
        }
    }
    // Return the size of the set, which is the number of distinct valid y values
    return n-1;
}

int main() {
    int t;
    cin >> t;
    
    // Vector to store results for each test case
    vector<int> results(t);
    
    // Iterate through test cases using a traditional for loop
    for (int i = 0; i < t; ++i) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        
        // Call the countPairs function for each test case
        results[i] = countPairs(k, l1, r1, l2, r2);
    }
    
    // Output the results
    for (int i = 0; i < t; ++i) {
        cout << results[i] << endl;
    }
    
    return 0;
}
