#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k;
    cin >> n >> k;
    int left = -1, right = n + 1;
    while (right - left > 1)
    {
        long long m = left + (right - left) / 2;
        if ((n - m) * (n - m + 1) / 2 - m > k)
            left = m;
        else
            right = m;
    }
    cout << right;
}