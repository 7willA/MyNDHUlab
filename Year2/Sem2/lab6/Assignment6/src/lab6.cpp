#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <cstdint>

using namespace std;
struct Activity {
    string name;
    int start;
    int finish;
    int value;
    int orig_id;   
};

// helper: time difference in ms
double get_time_ms(chrono::high_resolution_clock::time_point a,
                   chrono::high_resolution_clock::time_point b) {
    return chrono::duration<double, milli>(b - a).count();
}

bool compatible(const Activity& a, const Activity& b) {
    return a.finish <= b.start || b.finish <= a.start;
}

vector<Activity> read_input(const string& path) {
    ifstream in(path);
    if (!in) {
        cerr << "Cannot open " << path << "\n";
        exit(1);
    }
    int n;
    in >> n;
    vector<Activity> acts(n);
    for (int i = 0; i < n; i++) {
        in >> acts[i].name >> acts[i].start >> acts[i].finish >> acts[i].value;
        acts[i].orig_id = i;
    }
    return acts;
}
// Method 1: Greedy (earliest finish time)

struct Result {
    vector<int> picked;   
    long long total;
    double time_ms;
};

Result run_greedy(vector<Activity> acts) {
    auto t0 = chrono::high_resolution_clock::now();

    // sort by finish time ascending
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });

    Result r;
    r.total = 0;
    int last_finish = -1;   

    for (int i = 0; i < (int)acts.size(); i++) {
        if (acts[i].start >= last_finish) {
            r.picked.push_back(acts[i].orig_id);
            r.total += acts[i].value;
            last_finish = acts[i].finish;
        }
    }

    auto t1 = chrono::high_resolution_clock::now();
    r.time_ms = get_time_ms(t0, t1);
    return r;
}

// Method 2: Brute Force
Result run_brute(const vector<Activity>& acts) {
    auto t0 = chrono::high_resolution_clock::now();

    int n = (int)acts.size();
    Result r;
    r.total = 0;
    long long best = -1;
    uint64_t best_mask = 0;

    if (n > 30) {
        r.total = -1;
        auto t1 = chrono::high_resolution_clock::now();
        r.time_ms = get_time_ms(t0, t1);
        return r;
    }

    uint64_t total_subsets = 1ULL << n;

    for (uint64_t mask = 0; mask < total_subsets; mask++) {
        vector<int> chosen;
        long long val = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1ULL << i)) {
                chosen.push_back(i);
                val += acts[i].value;
            }
        }
        bool ok = true;
        for (int i = 0; i < (int)chosen.size() && ok; i++) {
            for (int j = i + 1; j < (int)chosen.size() && ok; j++) {
                if (!compatible(acts[chosen[i]], acts[chosen[j]])) {
                    ok = false;
                }
            }
        }
        if (ok && val > best) {
            best = val;
            best_mask = mask;
        }
    }

    r.total = best;
    for (int i = 0; i < n; i++) {
        if (best_mask & (1ULL << i)) {
            r.picked.push_back(acts[i].orig_id);
        }
    }

    auto t1 = chrono::high_resolution_clock::now();
    r.time_ms = get_time_ms(t0, t1);
    return r;
}
// Method 3: Dynamic Programming
int p_linear(const vector<Activity>& a, int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (a[j].finish <= a[i].start) return j;
    }
    return -1;
}
int p_binary(const vector<Activity>& a, int i) {
    int lo = 0, hi = i - 1, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid].finish <= a[i].start) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

Result run_dp(vector<Activity> acts, bool use_binary) {
    auto t0 = chrono::high_resolution_clock::now();

    int n = (int)acts.size();
    // sort by finish time
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = use_binary ? p_binary(acts, i) : p_linear(acts, i);
    }
    vector<long long> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long not_take = dp[i - 1];
        long long take = acts[i - 1].value + dp[p[i - 1] + 1];
        dp[i] = max(not_take, take);
    }
   // Result r;
    r.total = dp[n];
    int i = n;
    while (i > 0) {
        long long take = acts[i - 1].value + dp[p[i - 1] + 1];
        if (take > dp[i - 1]) {
            r.picked.push_back(acts[i - 1].orig_id);
            i = p[i - 1] + 1;
        } else {
            i = i - 1;
        }
    }
    // reverse so we print in time order
    reverse(r.picked.begin(), r.picked.end());

    auto t1 = chrono::high_resolution_clock::now();
    r.time_ms = get_time_ms(t0, t1);
    return r;
}

void print_result(const string& label, const Result& r, const vector<Activity>& acts) {
    cout << label << " Result:\n";
    if (r.total < 0) {
        cout << "  (skipped, n too large for this method)\n\n";
        return;
    }
    cout << "  Selected Activities: ";
    for (size_t i = 0; i < r.picked.size(); i++) {
        cout << acts[r.picked[i]].name;
        if (i + 1 < r.picked.size()) cout << " ";
    }
    cout << "\n  Total Value: " << r.total << "\n";
    cout << "  Running Time: " << fixed << setprecision(4) << r.time_ms << " ms\n\n";
}

int main(int argc, char** argv) {
    string path = (argc >= 2) ? string(argv[1]) : string("input.txt");
    string label = (argc >= 3) ? string(argv[2]) : string("input");

    vector<Activity> acts = read_input(path);
    int n = (int)acts.size();

    cout << "==============================================\n";
    cout << "Input file : " << path << "    (n = " << n << ")\n";
    cout << "==============================================\n";

    Result g  = run_greedy(acts);
    Result d1 = run_dp(acts, false);   // O(n^2)
    Result d2 = run_dp(acts, true);    // O(n log n)
    Result b;
    if (n <= 22) {
        b = run_brute(acts);
    } else {
        b.total = -1;
        b.time_ms = 0;
    }

    print_result("Greedy", g, acts);
    if (n <= 22) print_result("Brute Force", b, acts);
    else cout << "Brute Force Result:\n  (skipped, n > 22)\n\n";
    print_result("Dynamic Programming (linear p)", d1, acts);
    print_result("Dynamic Programming (binary p)", d2, acts);

    // append a row to results.csv
    bool need_header = false;
    {
        ifstream check("results.csv");
        if (!check.good()) need_header = true;
    }
    ofstream csv("results.csv", ios::app);
    if (need_header) {
        csv << "label,n,greedy_value,brute_value,dp_value,"
               "greedy_ms,brute_ms,dp_linear_ms,dp_binary_ms\n";
    }
    csv << label << "," << n << ","
        << g.total << ","
        << (n <= 22 ? b.total : -1) << ","
        << d2.total << ","
        << g.time_ms << ","
        << (n <= 22 ? b.time_ms : -1) << ","
        << d1.time_ms << ","
        << d2.time_ms << "\n";
    csv.close();

    return 0;
}
