#include <bits/stdc++.h>
using namespace std;
long long int countDivisors(long long int x) {
    set<long long int> divisors;
    for (long long int i = 1; i <= sqrt(x); ++i) {
        if (x % i == 0) {
            divisors.insert(i);         
            if (i != x / i) {
                divisors.insert(x / i); 
            }
        }
    }
    return divisors.size(); 
}

int main() {
   long long int x;
    cin >> x;
    long long int result = countDivisors(x);
    cout << result << endl;

    return 0;
}
