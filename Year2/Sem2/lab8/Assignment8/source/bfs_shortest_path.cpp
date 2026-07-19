#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void bfs_shortest_path(int source, int target, const vector<vector<int>>& adj, int V) {
    vector<int> dist(V, -1);
    vector<int> parent(V, -1);
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << "=== BFS Shortest Path ===" << endl;
    cout << "Source: " << source << endl;
    cout << "\nShortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == -1)
            cout << "  Node " << i << ": unreachable" << endl;
        else
            cout << "  Node " << i << ": " << dist[i] << " edge(s)" << endl;
    }

    cout << "\nPath from " << source << " to " << target << ": ";
    if (dist[target] == -1) {
        cout << "No path exists." << endl;
        return;
    }
    // Reconstruct path
    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur])
        path.push_back(cur);
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << "\nTotal edges: " << dist[target] << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    int source, target;
    cin >> source >> target;

    bfs_shortest_path(source, target, adj, V);
    return 0;
}
