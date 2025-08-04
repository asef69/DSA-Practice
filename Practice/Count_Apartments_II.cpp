#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;

int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int &count) {
    visited[x][y] = true;
    count++;

    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '.') {
            dfs(nx, ny, count);
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    vector<int> apartments;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int roomCount = 0;
                dfs(i, j, roomCount);
                apartments.push_back(roomCount);
            }
        }
    }

    if (apartments.empty()) {
        cout << 0 << endl;
        return 0;
    }

    sort(apartments.begin(), apartments.end());

    for (int i = 0; i < apartments.size(); i++) {
        cout << apartments[i];
        if (i != apartments.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
