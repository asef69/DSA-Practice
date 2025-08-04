#include <bits/stdc++.h>
using namespace std;
void solve()
{
    static vector<long long int> v;
    int query;
    cin >> query;
    if (query == 1)
    {
        long long int a;
        cin >> a;
        v.push_back(a);
    }
    else if (query == 2)
    {
        if (v.empty())
        {
            cout << "empty\n";
        }
        else
        {
            unordered_map<long long int, int> freq;
            for (auto num : v)
            {
                freq[num]++;
            }
            long long int min_freq_elem = -1;
            int min_freq = INT_MAX;

            for (auto &[num, count] : freq)
            {
                if (count < min_freq || (count == min_freq && num > min_freq_elem))
                {
                    min_freq = count;
                    min_freq_elem = num;
                }
            }
            cout << min_freq_elem << "\n";
            int removal_count = min_freq / 2;
            vector<long long int> new_v;

            for (auto num : v)
            {
                if (num == min_freq_elem && removal_count > 0)
                {
                    removal_count--;
                }
                else
                {
                    new_v.push_back(num);
                }
            }
            v = new_v;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}
