// ============================================================
// Floyd-Warshall Algorithm
// Computes all-pairs shortest paths using dynamic programming.
// Also reconstructs paths and can detect negative-weight cycles
// (a negative value on the diagonal dist[i][i]).
// Usage:
//   First line: V E  (vertices, edges)
//   Next E lines: u v w  (directed edge u->v with weight w)
//   Last line: source target  (for path reconstruction demo)
// ============================================================
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const long long INF = 1e15;

void print_path(int i, int j, const vector<vector<int>>& next) {
    if (next[i][j] == -1) {
        cout << "No path";
        return;
    }
    cout << i;
    while (i != j) {
        i = next[i][j];
        cout << " -> " << i;
    }
}

void floyd_warshall(int V, vector<vector<long long>>& dist, vector<vector<int>>& next) {
    // Core DP: try each intermediate vertex k
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next[i][j] = next[i][k];
                    }
                }
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<long long>> dist(V, vector<long long>(V, INF));
    vector<vector<int>> next(V, vector<int>(V, -1));

    // Initialize diagonal
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0;
        next[i][i] = i;
    }

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w < dist[u][v]) { // handle multiple edges
            dist[u][v] = w;
            next[u][v] = v;
        }
        // Undirected: also add reverse edge
        if (w < dist[v][u]) {
            dist[v][u] = w;
            next[v][u] = u;
        }
    }

    int src, tgt;
    cin >> src >> tgt;

    floyd_warshall(V, dist, next);

    cout << "=== Floyd-Warshall Algorithm ===" << endl;

    // Check for negative-weight cycles (negative diagonal)
    bool neg_cycle = false;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            neg_cycle = true;
            cout << "[WARNING] Negative-weight cycle detected involving node " << i << "!" << endl;
        }
    }

    if (!neg_cycle) {
        cout << "\nAll-Pairs Shortest Distance Matrix:" << endl;
        cout << "     ";
        for (int j = 0; j < V; j++) cout << "  [" << j << "] ";
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << "[" << i << "]  ";
            for (int j = 0; j < V; j++) {
                if (dist[i][j] == INF)
                    cout << "   INF ";
                else
                    cout << "  " << dist[i][j] << "   ";
                // Pad spacing (simple formatting)
                if (dist[i][j] >= 0 && dist[i][j] < 10) cout << " ";
            }
            cout << endl;
        }

        cout << "\nPath from " << src << " to " << tgt << ": ";
        print_path(src, tgt, next);
        if (dist[src][tgt] < INF)
            cout << "\nTotal distance: " << dist[src][tgt] << endl;
        else
            cout << "\nNo path exists." << endl;
    }

    return 0;
}
