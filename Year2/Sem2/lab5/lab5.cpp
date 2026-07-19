/*
 * Activity Selection Problem: Greedy Algorithm Strategy Comparison
 
 * Compile: g++ -std=c++17 -o lab5 lab5.cpp
 * Run:    ./lab5 sample.txt
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

// Data structure to represent one activity
struct Activity {
    string name;
    int start;
    int finish;
    int duration() const { return finish - start; }
};

// Helper: print the result of one strategy
void printResult(const string& label, const vector<Activity>& selected) {
    cout << label << ":\n";
    cout << "  Selected: ";
    for (int i = 0; i < (int)selected.size(); i++) {
        if (i > 0) cout << " ";
        cout << selected[i].name;
    }
    cout << "\n  Total selected: " << selected.size() << "\n\n";
}

// Helper: greedy scan (shared by all strategies)
// After the activities are sorted in whatever order,
// we scan and pick compatible ones.
vector<Activity> greedyScan(vector<Activity> acts) {
    vector<Activity> selected;
    int lastFinish = -1;

    for (const Activity& a : acts) {
        if (a.start >= lastFinish) {
            selected.push_back(a);
            lastFinish = a.finish;
        }
    }
    return selected;
}

// Strategy 1: Earliest Finish Time First  (OPTIMAL)
// Sort by finish time ascending. This is the classic
// greedy solution that guarantees the maximum number
// of non-overlapping activities.

vector<Activity> earliestFinishFirst(vector<Activity> acts) {
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.finish < b.finish;
    });
    return greedyScan(acts);
}

// Strategy 2: Earliest Start Time First  (NOT OPTIMAL)
// Sort by start time ascending. Intuitively it seems
// reasonable, but a single long activity that starts
// early can block many shorter ones.
vector<Activity> earliestStartFirst(vector<Activity> acts) {
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.start < b.start;
    });
    return greedyScan(acts);
}

// Strategy 3: Shortest Duration First  (NOT OPTIMAL)
// Sort by duration (finish - start) ascending. Short
// activities look attractive, but picking a short one
// in the middle can block more activities around it.
vector<Activity> shortestDurationFirst(vector<Activity> acts) {
    sort(acts.begin(), acts.end(), [](const Activity& a, const Activity& b) {
        return a.duration() < b.duration();
    });
    return greedyScan(acts);
}

// Strategy 4: Input Order  (NOT OPTIMAL)
// No sorting — just scan activities as given. Heavily
// depends on the input order, so results vary widely.
vector<Activity> inputOrderFirst(const vector<Activity>& acts) {
    return greedyScan(acts);
}

// Read activities from a stream
// Format:
//   n
//   name start finish
//   ...
vector<Activity> readActivities(istream& in) {
    int n;
    in >> n;
    vector<Activity> acts(n);
    for (int i = 0; i < n; i++) {
        in >> acts[i].name >> acts[i].start >> acts[i].finish;
    }
    return acts;
}

// Run all four strategies on a given set of activities
void runAllStrategies(const vector<Activity>& acts) {
    cout << "Input activities (" << acts.size() << " total):\n";
    cout << "  " << left << setw(6) << "Name"
                 << setw(8) << "Start"
                 << setw(8) << "Finish"
                 << "Duration\n";
    cout << "  " << string(32, '-') << "\n";
    for (const Activity& a : acts) {
        cout << "  " << left << setw(6) << a.name
                     << setw(8) << a.start
                     << setw(8) << a.finish
                     << a.duration() << "\n";
    }
    cout << "\n";

    printResult("Strategy 1 - Earliest Finish First (Optimal)", earliestFinishFirst(acts));
    printResult("Strategy 2 - Earliest Start First",            earliestStartFirst(acts));
    printResult("Strategy 3 - Shortest Duration First",         shortestDurationFirst(acts));
    printResult("Strategy 4 - Input Order First",               inputOrderFirst(acts));
}
// Main entry point
// Accepts an optional filename argument.
// If no argument, reads from standard input.

int main(int argc, char* argv[]) {
    cout << "=== Activity Selection Problem - Strategy Comparison ===\n\n";

    vector<Activity> activities;

    if (argc >= 2) {
        ifstream fin(argv[1]);
        if (!fin) {
            cerr << "Error: cannot open file \"" << argv[1] << "\"\n";
            return 1;
        }
        activities = readActivities(fin);
    } else {
        activities = readActivities(cin);
    }

    runAllStrategies(activities);

    return 0;
}
