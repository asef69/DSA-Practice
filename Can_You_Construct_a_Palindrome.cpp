#include <iostream>
#include <vector>
using namespace std;

void Palindrome(int n, int k, string s)
{
    vector<int> freq(26, 0);
    for (char c : s)
    {
        freq[c - 'a']++;
    }
    int odd = 0;
    for (int count : freq)
    {
        if (count % 2 != 0)
        {
            odd++;
        }
    }
    if (odd - 1 <= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    int n, k;
    string s;

    cin >> n >> k;
    cin >> s;

    Palindrome(n, k, s);

    return 0;
}
