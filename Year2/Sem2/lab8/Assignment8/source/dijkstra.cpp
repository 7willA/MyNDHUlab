#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<long long, int> pli; // (distance, vertex)

void dijkstra(int source, int target, const vector<vector<pair<int,int>>>& adj, int V) {
    vector<long long> dist(V, LLONG_MAX);
    vector<int> parent(V, -1);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        // Skip outdated entries
        if (d > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "=== Dijkstra Algorithm ===" << endl;
    cout << "Source: " << source << endl;
    cout << "\nShortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == LLONG_MAX)
            cout << "  Node " << i << ": unreachable" << endl;
        else
            cout << "  Node " << i << ": " << dist[i] << endl;
    }

    cout << "\nPath from " << source << " to " << target << ": ";
    if (dist[target] == LLONG_MAX) {
        cout << "No path exists." << endl;
        return;
    }
    vector<int> path;
    for (int cur = target; cur != -1; cur = parent[cur])
        path.push_back(cur);
    for (int i = (int)path.size() - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0) cout << " -> ";
    }
    cout << "\nTotal distance: " << dist[target] << endl;

    cout << "\n[NOTE] Dijkstra requires ALL edge weights to be non-negative." << endl;
    cout << "If negative weights exist, a confirmed shortest distance could later be" << endl;
    cout << "reduced by a negative edge, breaking the greedy assumption and giving" << endl;
    cout << "incorrect results. Use Bellman-Ford for graphs with negative edges." << endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); 
    }

    int source, target;
    cin >> source >> target;

    dijkstra(source, target, adj, V);
    return 0;
}
