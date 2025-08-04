#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

bool bellmanFord(int src, int n, vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                return true; 
            }
        }
    }

    return false; 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int src;
    cin >> src;

    vector<int> dist(n + 1, INF);

    bool hasNegativeCycle = bellmanFord(src, n, adj, dist);

    if (hasNegativeCycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int q;
    cin >> q;

    while (q--) {
        int dest;
        cin >> dest;

        if (dist[dest] == INF) {
            cout << "Not Possible" << endl;
        } else {
            cout << dist[dest] << endl;
        }
    }

    return 0;
}