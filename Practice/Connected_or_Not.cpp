#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> adj(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x, y;
        cin >> x >> y;

        if (x == y || adj[x][y])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
