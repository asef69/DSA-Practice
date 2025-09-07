#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> list[n];
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        vector<int> neighbours = list[x];
        if (neighbours.empty())
        {
            cout << "-1" << endl;
        }
        else
        {
            sort(neighbours.begin(), neighbours.end());
            reverse(neighbours.begin(), neighbours.end());
            for (int i = 0; i < neighbours.size(); i++)
            {
                cout << neighbours[i] << " ";
            }
            cout << endl;
        }
    }
}