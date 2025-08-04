#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(int src, int n, vector<vector<pii>>& adj) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        bool found = false;
        for (auto& edge : adj[u]) {
            if (edge.first == v) {
                edge.second = min(edge.second, w);
                found = true;
                break;
            }
        }

        if (!found) {
            adj[u].push_back({v, w});
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int src, dest;
        cin >> src >> dest;

        vector<int> dist = dijkstra(src, n, adj);

        if (dist[dest] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << dist[dest] << endl;
        }
    }

    return 0;
}