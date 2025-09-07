#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > grid;
vector<vector<long long> > dp;

long long sum(int i, int j) {
    if (i == n && j == m) {
        return grid[i - 1][j - 1];
    }

    if (i > n || j > m) {
        return INT_MIN;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    long long down = sum(i + 1, j);
    long long right = sum(i, j + 1);

    dp[i][j] = grid[i - 1][j - 1] + max(down, right);

    return dp[i][j];
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<int>(m));
    dp.resize(n + 1, vector<long long>(m + 1, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    long long result = sum(1, 1);
    cout << result << endl;

    return 0;
}