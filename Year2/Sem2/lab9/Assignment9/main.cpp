#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
#include <unordered_map>
using namespace std;

int N;                         // total number of nodes
vector<vector<int>> cap;       // residual capacity matrix
bool verbose = true;           // print every augmenting path 

/* BFS over the residual graph; records the path in parent[].
 * Returns true when an augmenting path source -> sink exists. */
bool bfs(int source, int sink, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[source] = source;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = 0; v < N; ++v) {
            if (parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                if (v == sink) return true;
                q.push(v);
            }
        }
    }
    return false;
}

/* Edmonds-Karp: BFS shortest augmenting paths until none remain. */
int maxFlow(int source, int sink) {
    int flow = 0, iteration = 0;
    vector<int> parent(N);
    while (bfs(source, sink, parent)) {
        int pathFlow = INT_MAX;                       
        for (int v = sink; v != source; v = parent[v])
            pathFlow = min(pathFlow, cap[parent[v]][v]);
        for (int v = sink; v != source; v = parent[v]) {  // update residuals
            int u = parent[v];
            cap[u][v] -= pathFlow;                    // forward edge
            cap[v][u] += pathFlow;                    // backward edge
        }
        if (verbose) {
            vector<int> path;
            for (int v = sink; v != source; v = parent[v]) path.push_back(v);
            path.push_back(source);
            cout << "  Augmenting path #" << ++iteration
                 << " (flow +" << pathFlow << "): ";
            for (int i = (int)path.size() - 1; i >= 0; --i)
                cout << path[i] << (i ? " -> " : "");
            cout << "\n";
        }
        flow += pathFlow;
    }
    return flow;
}

int main(int argc, char** argv) {
    istream* in = &cin;
    ifstream fin;
    if (argc > 1) {
        fin.open(argv[1]);
        if (!fin) { cerr << "Cannot open file: " << argv[1] << "\n"; return 1; }
        in = &fin;
    }

    int numStudents, numTasks;
    if (!(*in >> numStudents >> numTasks)) { cerr << "Invalid input.\n"; return 1; }

    int source = 0;
    int sink   = numStudents + numTasks + 1;
    N = numStudents + numTasks + 2;
    cap.assign(N, vector<int>(N, 0));

    vector<string> studentName(numStudents), taskName(numTasks);
    vector<int>    studentCap(numStudents),  taskCap(numTasks);
    // remember each student's accepted task names until task indices are known
    vector<vector<string>> accept(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        int k;
        *in >> studentName[i] >> studentCap[i] >> k;
        accept[i].resize(k);
        for (int t = 0; t < k; ++t) *in >> accept[i][t];
    }

    unordered_map<string,int> taskIndex;
    for (int j = 0; j < numTasks; ++j) {
        *in >> taskName[j] >> taskCap[j];
        taskIndex[taskName[j]] = j;
    }

    auto taskNode = [&](int j) { return numStudents + 1 + j; };

    // build edges
    for (int i = 0; i < numStudents; ++i) {
        cap[source][i + 1] = studentCap[i];               // source -> student
        for (const string& tn : accept[i]) {
            auto it = taskIndex.find(tn);
            if (it == taskIndex.end()) {
                cerr << "Warning: student " << studentName[i]
                     << " lists unknown task '" << tn << "'\n";
                continue;
            }
            cap[i + 1][taskNode(it->second)] = 1;         // student -> task
        }
    }
    for (int j = 0; j < numTasks; ++j)
        cap[taskNode(j)][sink] = taskCap[j];              // task -> sink

    // This is to keep a copy, that way we can detect which student->task edges carry flow
    vector<vector<int>> origCap = cap;

    cout << "=== Edmonds-Karp execution ===\n";
    int result = maxFlow(source, sink);

    cout << "\nMaximum Matching: " << result << "\n";
    cout << "Assignments:\n";
    int shown = 0;
    for (int i = 0; i < numStudents; ++i)
        for (int j = 0; j < numTasks; ++j) {
            int u = i + 1, v = taskNode(j);
            // flow on a forward edge = original capacity - remaining residual
            int f = origCap[u][v] - cap[u][v];
            if (f > 0) { cout << "  " << studentName[i] << " -> "
                              << taskName[j] << "\n"; ++shown; }
        }
    if (shown == 0) cout << "  (no assignments)\n";
    return 0;
}
