// Lab 3 - High Dimensional Vector Range Search
// I implemented brute force and KD-tree for this assignment
// compile: g++ -O2 -std=c++17 -o lab3 lab3_search.cpp
// run: ./lab3

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <iomanip>

using namespace std;

// calculate euclidean distance between two vectors
double euclidean_dist(const vector<double>& a, const vector<double>& b) {
    double sum = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        double d = a[i] - b[i];
        sum += d * d;
    }
    return sqrt(sum);
}

// generate random dataset with fixed seed so results are reproducible
vector<vector<double>> gen_data(int n, int dim, int seed = 42) {
    mt19937 rng(seed);
    uniform_real_distribution<double> dist(0.0, 10.0);
    vector<vector<double>> data(n, vector<double>(dim));
    for (auto& v : data)
        for (auto& x : v)
            x = dist(rng);
    return data;
}

vector<vector<double>> gen_queries(int count, int dim, int seed = 200) {
    mt19937 rng(seed);
    uniform_real_distribution<double> dist(0.0, 10.0);
    vector<vector<double>> qs(count, vector<double>(dim));
    for (auto& q : qs)
        for (auto& x : q)
            x = dist(rng);
    return qs;
}

// -------------------------------------------------------
// Method 1: Brute Force
// just check every point one by one
// time complexity: O(n * d)
// -------------------------------------------------------
vector<int> brute_force(const vector<vector<double>>& data,
                        const vector<double>& query, double r) {
    vector<int> res;
    for (int i = 0; i < (int)data.size(); i++) {
        if (euclidean_dist(data[i], query) <= r)
            res.push_back(i);
    }
    return res;
}

// -------------------------------------------------------
// Method 2: KD-Tree
// divide the space by splitting on one dimension at a time
// during search, skip branches that cant possibly have points in range
// build: O(n log n), query: O(log n) average but worse in high dims
// -------------------------------------------------------
struct Node {
    vector<double> pt;
    int idx;
    int split;  // which dimension we split on
    Node* left;
    Node* right;
    Node(vector<double> p, int i, int s)
        : pt(p), idx(i), split(s), left(nullptr), right(nullptr) {}
};

Node* build_tree(vector<pair<vector<double>, int>>& pts, int depth, int dim) {
    if (pts.empty()) return nullptr;

    int d = depth % dim;
    sort(pts.begin(), pts.end(),
         [d](const pair<vector<double>,int>& a, const pair<vector<double>,int>& b) {
             return a.first[d] < b.first[d];
         });

    int m = pts.size() / 2;
    Node* node = new Node(pts[m].first, pts[m].second, d);

    vector<pair<vector<double>,int>> left_pts(pts.begin(), pts.begin() + m);
    vector<pair<vector<double>,int>> right_pts(pts.begin() + m + 1, pts.end());

    node->left  = build_tree(left_pts,  depth + 1, dim);
    node->right = build_tree(right_pts, depth + 1, dim);
    return node;
}

void kd_search(Node* node, const vector<double>& q, double r, vector<int>& res) {
    if (!node) return;

    if (euclidean_dist(node->pt, q) <= r)
        res.push_back(node->idx);

    double diff = q[node->split] - node->pt[node->split];

    // go to the closer side first
    Node* near  = diff <= 0 ? node->left  : node->right;
    Node* far   = diff <= 0 ? node->right : node->left;

    kd_search(near, q, r, res);

    // only check far side if the hyperplane is within radius
    if (fabs(diff) <= r)
        kd_search(far, q, r, res);
}

void free_tree(Node* node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    delete node;
}

// simple timing helper
using TimePoint = chrono::time_point<chrono::high_resolution_clock>;
double get_time_ms(TimePoint start, TimePoint end) {
    return chrono::duration<double, milli>(end - start).count();
}

int main() {
    cout << fixed << setprecision(4);
    cout << "Lab 3 - Range Search Experiments\n\n";

    int num_queries = 25;
    int reps = 3;

    ofstream csv("lab3_results.csv");
    csv << "experiment,param_val,bf_ms,kd_build_ms,kd_ms,bf_found,kd_found\n";

    // === Experiment 1: varying n (d=16, r=1.5) ===
    cout << "Exp 1: Varying n (d=16, r=1.5)\n";
    cout << setw(10) << "n"
         << setw(12) << "BF(ms)"
         << setw(14) << "KD_build(ms)"
         << setw(12) << "KD(ms)"
         << setw(10) << "found\n";
    cout << string(58, '-') << "\n";

    vector<int> sizes = {1000, 5000, 10000, 50000, 100000};
    for (int n : sizes) {
        double tot_bf=0, tot_kd=0, tot_build=0, tot_found=0;

        for (int rep = 0; rep < reps; rep++) {
            auto data    = gen_data(n, 16, 42 + rep);
            auto queries = gen_queries(num_queries, 16, 200 + rep);

            // brute force
            double bf_t = 0; double bf_found = 0;
            for (auto& q : queries) {
                auto t0 = chrono::high_resolution_clock::now();
                auto r  = brute_force(data, q, 1.5);
                auto t1 = chrono::high_resolution_clock::now();
                bf_t += get_time_ms(t0, t1);
                bf_found += r.size();
            }
            tot_bf    += bf_t / num_queries;
            tot_found += bf_found / num_queries;

            // kd-tree
            vector<pair<vector<double>,int>> indexed;
            for (int i = 0; i < n; i++) indexed.push_back({data[i], i});
            auto b0   = chrono::high_resolution_clock::now();
            Node* tree = build_tree(indexed, 0, 16);
            auto b1   = chrono::high_resolution_clock::now();
            tot_build += get_time_ms(b0, b1);

            double kd_t = 0;
            for (auto& q : queries) {
                vector<int> res;
                auto t0 = chrono::high_resolution_clock::now();
                kd_search(tree, q, 1.5, res);
                auto t1 = chrono::high_resolution_clock::now();
                kd_t += get_time_ms(t0, t1);
            }
            tot_kd += kd_t / num_queries;
            free_tree(tree);
        }

        double bf_avg    = tot_bf    / reps;
        double kd_avg    = tot_kd    / reps;
        double build_avg = tot_build / reps;
        double found_avg = tot_found / reps;

        cout << setw(10) << n
             << setw(12) << bf_avg
             << setw(14) << build_avg
             << setw(12) << kd_avg
             << setw(10) << found_avg << "\n";

        csv << "vary_n," << n << "," << bf_avg << "," << build_avg << ","
            << kd_avg << "," << found_avg << "," << found_avg << "\n";
    }

    // === Experiment 2: varying d (n=10000, r=1.5) ===
    cout << "\nExp 2: Varying d (n=10000, r=1.5)\n";
    cout << setw(10) << "d"
         << setw(12) << "BF(ms)"
         << setw(14) << "KD_build(ms)"
         << setw(12) << "KD(ms)"
         << setw(10) << "found\n";
    cout << string(58, '-') << "\n";

    vector<int> dims = {4, 8, 16, 32, 64, 128};
    for (int d : dims) {
        double tot_bf=0, tot_kd=0, tot_build=0, tot_found=0;

        for (int rep = 0; rep < reps; rep++) {
            auto data    = gen_data(10000, d, 42 + rep);
            auto queries = gen_queries(num_queries, d, 200 + rep);

            double bf_t = 0, bf_found = 0;
            for (auto& q : queries) {
                auto t0 = chrono::high_resolution_clock::now();
                auto r  = brute_force(data, q, 1.5);
                auto t1 = chrono::high_resolution_clock::now();
                bf_t += get_time_ms(t0, t1);
                bf_found += r.size();
            }
            tot_bf    += bf_t / num_queries;
            tot_found += bf_found / num_queries;

            vector<pair<vector<double>,int>> indexed;
            for (int i = 0; i < 10000; i++) indexed.push_back({data[i], i});
            auto b0   = chrono::high_resolution_clock::now();
            Node* tree = build_tree(indexed, 0, d);
            auto b1   = chrono::high_resolution_clock::now();
            tot_build += get_time_ms(b0, b1);

            double kd_t = 0;
            for (auto& q : queries) {
                vector<int> res;
                auto t0 = chrono::high_resolution_clock::now();
                kd_search(tree, q, 1.5, res);
                auto t1 = chrono::high_resolution_clock::now();
                kd_t += get_time_ms(t0, t1);
            }
            tot_kd += kd_t / num_queries;
            free_tree(tree);
        }

        double bf_avg    = tot_bf    / reps;
        double kd_avg    = tot_kd    / reps;
        double build_avg = tot_build / reps;
        double found_avg = tot_found / reps;

        cout << setw(10) << d
             << setw(12) << bf_avg
             << setw(14) << build_avg
             << setw(12) << kd_avg
             << setw(10) << found_avg << "\n";

        csv << "vary_d," << d << "," << bf_avg << "," << build_avg << ","
            << kd_avg << "," << found_avg << "," << found_avg << "\n";
    }

    // === Experiment 3: varying radius (n=10000, d=16) ===
    cout << "\nExp 3: Varying r (n=10000, d=16)\n";
    cout << setw(10) << "r"
         << setw(12) << "BF(ms)"
         << setw(14) << "KD_build(ms)"
         << setw(12) << "KD(ms)"
         << setw(10) << "found\n";
    cout << string(58, '-') << "\n";

    vector<double> radii = {0.5, 1.5, 3.0};
    for (double r : radii) {
        double tot_bf=0, tot_kd=0, tot_build=0, tot_found=0;

        for (int rep = 0; rep < reps; rep++) {
            auto data    = gen_data(10000, 16, 42 + rep);
            auto queries = gen_queries(num_queries, 16, 200 + rep);

            double bf_t = 0, bf_found = 0;
            for (auto& q : queries) {
                auto t0 = chrono::high_resolution_clock::now();
                auto rs = brute_force(data, q, r);
                auto t1 = chrono::high_resolution_clock::now();
                bf_t += get_time_ms(t0, t1);
                bf_found += rs.size();
            }
            tot_bf    += bf_t / num_queries;
            tot_found += bf_found / num_queries;

            vector<pair<vector<double>,int>> indexed;
            for (int i = 0; i < 10000; i++) indexed.push_back({data[i], i});
            auto b0   = chrono::high_resolution_clock::now();
            Node* tree = build_tree(indexed, 0, 16);
            auto b1   = chrono::high_resolution_clock::now();
            tot_build += get_time_ms(b0, b1);

            double kd_t = 0;
            for (auto& q : queries) {
                vector<int> res;
                auto t0 = chrono::high_resolution_clock::now();
                kd_search(tree, q, r, res);
                auto t1 = chrono::high_resolution_clock::now();
                kd_t += get_time_ms(t0, t1);
            }
            tot_kd += kd_t / num_queries;
            free_tree(tree);
        }

        double bf_avg    = tot_bf    / reps;
        double kd_avg    = tot_kd    / reps;
        double build_avg = tot_build / reps;
        double found_avg = tot_found / reps;

        cout << setw(10) << r
             << setw(12) << bf_avg
             << setw(14) << build_avg
             << setw(12) << kd_avg
             << setw(10) << found_avg << "\n";

        csv << "vary_r," << r << "," << bf_avg << "," << build_avg << ","
            << kd_avg << "," << found_avg << "," << found_avg << "\n";
    }

    csv.close();
    cout << "\nResults saved to lab3_results.csv\n";
    return 0;
}
