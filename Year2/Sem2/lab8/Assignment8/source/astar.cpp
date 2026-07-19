
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <tuple>
#include <algorithm>
using namespace std;

typedef tuple<int,int,int> T3; // (f, row, col)

// Manhattan distance heuristic
int heuristic(int r1, int c1, int r2, int c2) {
    return abs(r1 - r2) + abs(c1 - c2);
}

// 4-directional movement
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void astar(const vector<vector<int>>& grid, int rows, int cols,
           int sr, int sc, int tr, int tc) {
    const int INF = INT_MAX;
    vector<vector<int>> g_cost(rows, vector<int>(cols, INF));
    vector<vector<pair<int,int>>> parent(rows, vector<pair<int,int>>(cols, {-1,-1}));

    // min-heap: (f, row, col)
    priority_queue<T3, vector<T3>, greater<T3>> pq;

    g_cost[sr][sc] = 0;
    int h = heuristic(sr, sc, tr, tc);
    pq.push({h, sr, sc});

    int nodes_expanded_astar = 0;

    while (!pq.empty()) {
        auto [f, r, c] = pq.top(); pq.pop();

        // Skip outdated entries
        if (f > g_cost[r][c] + heuristic(r, c, tr, tc)) continue;

        nodes_expanded_astar++;

        if (r == tr && c == tc) break;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (grid[nr][nc] == 1) continue; // blocked
            int new_g = g_cost[r][c] + 1;
            if (new_g < g_cost[nr][nc]) {
                g_cost[nr][nc] = new_g;
                parent[nr][nc] = {r, c};
                int new_f = new_g + heuristic(nr, nc, tr, tc);
                pq.push({new_f, nr, nc});
            }
        }
    }

    cout << "=== A* Search Algorithm ===" << endl;
    cout << "Grid size: " << rows << " x " << cols << endl;
    cout << "Start: (" << sr << ", " << sc << ")  Target: (" << tr << ", " << tc << ")" << endl;
    cout << "Heuristic: Manhattan distance  h(n) = |row_n - row_t| + |col_n - col_t|" << endl;

    if (g_cost[tr][tc] == INF) {
        cout << "\nNo path found from start to target." << endl;
        return;
    }

    // Reconstruct path
    vector<pair<int,int>> path;
    for (auto cur = make_pair(tr,tc); cur.first != -1; cur = parent[cur.first][cur.second])
        path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << "\nPath found:" << endl;
    for (auto [r, c] : path)
        cout << "  (" << r << ", " << c << ")" << endl;
    cout << "Path length (cost): " << g_cost[tr][tc] << endl;
    cout << "Nodes expanded by A*: " << nodes_expanded_astar << endl;

    // Run Dijkstra (h=0) on same grid to compare expanded nodes
    vector<vector<int>> g_dijk(rows, vector<int>(cols, INF));
    priority_queue<T3, vector<T3>, greater<T3>> pq2;
    g_dijk[sr][sc] = 0;
    pq2.push({0, sr, sc});
    int nodes_expanded_dijk = 0;
    while (!pq2.empty()) {
        auto [d, r, c] = pq2.top(); pq2.pop();
        if (d > g_dijk[r][c]) continue;
        nodes_expanded_dijk++;
        if (r == tr && c == tc) break;
        for (int dir = 0; dir < 4; dir++) {
            int nr = r + dr[dir], nc = c + dc[dir];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (grid[nr][nc] == 1) continue;
            if (g_dijk[r][c] + 1 < g_dijk[nr][nc]) {
                g_dijk[nr][nc] = g_dijk[r][c] + 1;
                pq2.push({g_dijk[nr][nc], nr, nc});
            }
        }
    }

    cout << "\nComparison with Dijkstra (h=0, no heuristic):" << endl;
    cout << "  Dijkstra nodes expanded: " << nodes_expanded_dijk << endl;
    cout << "  A* nodes expanded:       " << nodes_expanded_astar << endl;
    cout << "  A* expanded " << nodes_expanded_dijk - nodes_expanded_astar
         << " fewer nodes => more efficient with heuristic guidance." << endl;

    // Visualize grid with path
    vector<vector<char>> display(rows, vector<char>(cols, '.'));
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (grid[r][c]) display[r][c] = '#';
    for (auto [r, c] : path) display[r][c] = '*';
    display[sr][sc] = 'S';
    display[tr][tc] = 'T';

    cout << "\nGrid visualization ('S'=start, 'T'=target, '*'=path, '#'=wall):" << endl;
    for (int r = 0; r < rows; r++) {
        cout << "  ";
        for (int c = 0; c < cols; c++) cout << display[r][c] << " ";
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            cin >> grid[r][c];

    int sr, sc, tr, tc;
    cin >> sr >> sc >> tr >> tc;

    astar(grid, rows, cols, sr, sc, tr, tc);
    return 0;
}
