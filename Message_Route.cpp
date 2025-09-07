#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100001];  // Adjacency list to store the graph
bool visited[100001];     // To track visited nodes
int parent[100001];       // To store the parent of each node for path reconstruction

void bfs(int start, int n) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;  // Start node has no parent

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Traverse all neighbors of the current node
        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = node;  // Set the parent of the neighbor
            }
        }
    }

    // If the destination node `n` is not visited, it's impossible
    if (!visited[n]) {
        cout << "IMPOSSIBLE";
    } else {
        // Reconstruct the path from `n` to `1` using the parent array
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());  // Reverse to get the path from 1 to n

        // Output the number of computers and the path
        cout << path.size() << endl;
        for (int v : path) {
            cout << v << " ";
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Initialize visited and parent arrays
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));

    // Read the connections and build the adjacency list
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);  // Since the connections are bidirectional
    }

    // Perform BFS starting from computer 1
    bfs(1, n);

    return 0;
}