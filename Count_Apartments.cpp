#include<bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
    stack<pair<int, int>> s;
    s.push({x, y});
    visited[x][y] = true;
    while (!s.empty()) {
        int cx = s.top().first;
        int cy = s.top().second;
        s.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                s.push({nx, ny});
            }
        }
    }
}

int countApartments(vector<vector<char>>& grid, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int apartmentCount = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                dfs(i, j, grid, visited, n, m);
                apartmentCount++;
            }
        }
    }

    return apartmentCount;
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
    cout << countApartments(grid, n, m) << endl;

    return 0;
}
