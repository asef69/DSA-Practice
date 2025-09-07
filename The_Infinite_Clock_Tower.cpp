#include <iostream>
#include <vector>
#include <cmath>

const int MOD = 1000000007;

using namespace std;

// Function to calculate how the number of digits changes
int calculate_digits(int N, int H) {
    vector<int> digits;
    
    // Extract digits of the number N
    while (N > 0) {
        digits.push_back(N % 10);
        N /= 10;
    }
    
    // Reverse digits to process from most significant to least
    reverse(digits.begin(), digits.end());
    
    // Track the total number of digits
    long long total_digits = digits.size();
    
    // Perform H transformations
    for (int hour = 0; hour < H; ++hour) {
        long long new_digits_count = 0;
        
        // Process each digit in the current number
        for (int digit : digits) {
            int new_digit = digit + 2;
            
            if (new_digit >= 10) {
                // If the digit overflows (e.g., 9 becomes 11), it splits into two digits
                new_digits_count += 2;  // One digit becomes two
            } else {
                // Otherwise, it stays as one digit
                new_digits_count += 1;
            }
        }
        
        // Update the number of digits after this transformation
        total_digits = new_digits_count % MOD;
    }
    
    return total_digits;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, H;
        cin >> N >> H;
        
        // Calculate the number of digits after H transformations
        cout << calculate_digits(N, H) << endl;
    }
    
    return 0;
}
