#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValid(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '.' && !visited[x][y];
}

void dfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    stack<pair<int, int>> st;
    st.push({x, y});
    visited[x][y] = true;

    while (!st.empty()) {
        auto current = st.top();
        st.pop();
        int cx = current.first;
        int cy = current.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (isValid(nx, ny, n, m, grid, visited)) {
                visited[nx][ny] = true;
                st.push({nx, ny});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    if (grid[x1][y1] != '.' || grid[x2][y2] != '.') {
        cout << "NO" << endl;
        return 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    dfs(x1, y1, n, m, grid, visited);

    if (visited[x2][y2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}