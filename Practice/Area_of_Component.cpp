#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int area = 1;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                area++;
                q.push({nx, ny});
            }
        }
    }

    return area;
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

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int minArea = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int area = bfs(i, j, n, m, grid, visited);
                if (area < minArea) {
                    minArea = area;
                }
            }
        }
    }

    if (minArea == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << minArea << endl;
    }

    return 0;
}