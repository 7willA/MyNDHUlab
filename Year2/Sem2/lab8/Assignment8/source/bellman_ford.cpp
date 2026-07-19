#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellman_ford(int source, int target, const vector<Edge>& edges, int V) {
    const long long INF = LLONG_MAX / 2;
    vector<long long> dist(V, INF);
    vector<int> parent(V, -1);

    dist[source] = 0;

    // Relax all edges |V|-1 times
    for (int i = 0; i < V - 1; i++) {
        bool updated = false;
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                updated = true;
            }
        }
        if (!updated) break; // Early exit: no more updates possible
    }

    // Check for negative-weight cycles (V-th relaxation)
    bool has_negative_cycle = false;
    int neg_cycle_node = -1;
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            has_negative_cycle = true;
            neg_cycle_node = e.v;
            break;
        }
    }

    cout << "=== Bellman-Ford Algorithm ===" << endl;
    cout << "Source: " << source << endl;

    if (has_negative_cycle) {
        cout << "\n[WARNING] Negative-weight cycle detected reachable from source " << source << "!" << endl;
        cout << "Shortest distances are not well-defined (can be -infinity)." << endl;
        cout << "A node affected by the cycle: " << neg_cycle_node << endl;
        return;
    }

    cout << "\nNo negative-weight cycle detected." << endl;
    cout << "\nShortest distances from source " << source << ":" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << "  Node " << i << ": unreachable" << endl;
        else
            cout << "  Node " << i << ": " << dist[i] << endl;
    }

    cout << "\nPath from " << source << " to " << target << ": ";
    if (dist[target] == INF) {
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
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // directed graph
    }

    int source, target;
    cin >> source >> target;

    bellman_ford(source, target, edges, V);
    return 0;
}
