#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Common example data
    vector<string> names  = {"A", "B", "C", "D"};
    vector<int>    weight = {  6,   3,   4,   2 };
    vector<int>    value  = { 30,  14,  16,   9 };
    int n = names.size();
    int W = 10; // knapsack capacity

    cout << "Items: ";
    for (int i = 0; i < n; i++)
        cout << names[i] << "(w=" << weight[i] << ",v=" << value[i] << ") ";
    cout << "\nKnapsack capacity W = " << W << "\n\n";

    // -------------------------------------------------------------------
    // 1D space-optimized DP  (O(W) space)
    // -------------------------------------------------------------------
    // dp[w] = maximum value achievable with exactly capacity w
    // Initialised to 0 (empty knapsack = 0 value)
    vector<int> dp(W + 1, 0);

    // track[w] = index of the item last added to reach dp[w]
    //            (-1 means no item was added for this capacity)
    vector<int> track(W + 1, -1);

    // --- Fill DP ---
    // Outer loop: consider each item type
    for (int i = 0; i < n; i++) {
        // Inner loop: ASCENDING from weight[i] to W
        // Because dp[w - weight[i]] is updated earlier in the SAME pass,
        // item i can contribute multiple times (unbounded behaviour).
        for (int w = weight[i]; w <= W; w++) {
            int withItem = dp[w - weight[i]] + value[i];
            if (withItem > dp[w]) {
                dp[w]    = withItem; // better value found
                track[w] = i;        // remember which item gave the improvement
            }
        }
    }

    // --- Output maximum value ---
    cout << "=== Unbounded Knapsack (1D DP, O(W) space) ===" << endl;
    cout << "Maximum total value = " << dp[W] << endl;

    // --- Reconstruct selected items ---
    // Follow the track chain backward from capacity W.
    vector<string> selected;
    int cap = W;
    while (cap > 0 && track[cap] != -1) {
        int idx = track[cap];
        selected.push_back(names[idx]);
        cap -= weight[idx]; // "undo" this item's weight
    }
    // Items come out in reverse order of selection; reverse for readability
    reverse(selected.begin(), selected.end());

    cout << "Selected items (with repetition allowed): ";
    for (const auto& s : selected) cout << s << " ";
    cout << endl;

    // --- Show how many times each item was selected ---
    cout << "Item counts:" << endl;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (const auto& s : selected)
            if (s == names[i]) cnt++;
        if (cnt > 0)
            cout << "  " << names[i] << " x" << cnt << endl;
    }

    cout << endl;
    cout << "Time  complexity: O(nW)" << endl;
    cout << "Space complexity: O(W)  [dp[] and track[] arrays only]" << endl;

    return 0;
}
