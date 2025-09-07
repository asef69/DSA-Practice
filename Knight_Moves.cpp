#include <bits/stdc++.h>
using namespace std;

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(int n, int m, int kx, int ky, int qx, int qy) {
    if (kx == qx && ky == qy) return 0;

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> q;

    q.push({kx, ky});
    dist[kx][ky] = 0;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        int cx = current.first;
        int cy = current.second;

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == INT_MAX) {
                dist[nx][ny] = dist[cx][cy] + 1;
                if (nx == qx && ny == qy) {
                    return dist[nx][ny];
                }
                q.push({nx, ny});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int kx, ky;
        cin >> kx >> ky;

        int qx, qy;
        cin >> qx >> qy;

        int result = bfs(n, m, kx, ky, qx, qy);
        cout << result << endl;
    }

    return 0;
}