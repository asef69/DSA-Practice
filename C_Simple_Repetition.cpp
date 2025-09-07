#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Optimized prime check function
bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

void check_concatenated_prime(long long a, long long b) {
    // Special case: if a is 1, the result can't be prime
    if (a == 1) {
        cout << "NO" << endl;
        return;
    }
    
    // For b == 0, we just check the original number
    if (b == 0) {
        cout << (is_prime(a) ? "YES" : "NO") << endl;
        return;
    }
    
    // Numbers ending with even digit or 5 (except 2 and 5) can't be prime
    int last_digit = a % 10;
    if ((last_digit % 2 == 0 || last_digit == 5) && a != 2 && a != 5) {
        cout << "NO" << endl;
        return;
    }
    
    // For b >= 1, the concatenated number is divisible by original a
    // So it can only be prime if a is prime and b == 0 (already handled)
    cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        check_concatenated_prime(a, b);
    }
    return 0;
}