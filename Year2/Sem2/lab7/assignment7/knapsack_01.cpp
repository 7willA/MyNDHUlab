#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// -----------------------------------------------------------------------
// Part 1: 2D DP with backtracking to find selected items
// -----------------------------------------------------------------------
void solve2D(const vector<string>& names,
             const vector<int>& weight,
             const vector<int>& value,
             int n, int W)
{
    // --- Initialise DP table ---
    // dp[i][w] = max total value using the first i items with capacity w.
    // Base case: dp[0][w] = 0 for all w  (no items -> no value)
    //            dp[i][0] = 0 for all i  (zero capacity -> no value)
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // --- Fill DP table row by row ---
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            
            dp[i][w] = dp[i - 1][w];

            
            if (weight[i - 1] <= w) {
                int withItem = dp[i - 1][w - weight[i - 1]] + value[i - 1];
                
                dp[i][w] = max(dp[i][w], withItem);
            }
        }
    }

    // --- Maximum value is at dp[n][W] ---
    cout << "=== 2D DP Solution ===" << endl;
    cout << "Maximum total value = " << dp[n][W] << endl;

    // --- Backtrack through the DP table to find which items were selected ---
    // Starting from dp[n][W]: if dp[i][w] != dp[i-1][w], item i was taken.
    vector<string> selected;
    int w = W;
    for (int i = n; i >= 1; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected.push_back(names[i - 1]);
            w -= weight[i - 1]; // reduce capacity by the item's weight
        }
    }
    // Reverse so items appear in original order
    reverse(selected.begin(), selected.end());

    cout << "Selected items: ";
    for (const auto& s : selected) cout << s << " ";
    cout << endl << endl;
}

// -----------------------------------------------------------------------
// Part 2: 1D space-optimized DP (O(W) space)
// -----------------------------------------------------------------------
void solve1D(const vector<string>& names,
             const vector<int>& weight,
             const vector<int>& value,
             int n, int W)
{
    // dp[w] = max total value achievable with capacity w (using items seen so far)
    // Initially all zero (no items -> no value)
    vector<int> dp(W + 1, 0);

    // track[w] = index of the last item added to reach dp[w] (for reconstruction)
    vector<int> track(W + 1, -1);

    // --- Update rule ---
    // For each item i, update dp from W DOWN to weight[i-1].
    // Descending order is critical: it ensures dp[w - weight[i-1]] still
    // reflects the state BEFORE item i was considered, so we cannot pick
    // the same item twice (0/1 constraint).
    // If we went ascending, dp[w - weight[i-1]] might already include item i,
    // causing it to be selected multiple times (which would be Unbounded Knapsack).
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weight[i]; w--) {
            int withItem = dp[w - weight[i]] + value[i];
            if (withItem > dp[w]) {
                dp[w] = withItem;
                track[w] = i; // record that item i was chosen for capacity w
            }
        }
    }

    cout << "=== 1D Space-Optimized DP Solution ===" << endl;
    cout << "Maximum total value = " << dp[W] << endl;

    // --- Reconstruct selected items using track[] ---
    vector<string> selected;
    int cap = W;
    while (cap > 0 && track[cap] != -1) {
        int idx = track[cap];
        selected.push_back(names[idx]);
        cap -= weight[idx]; // move to the capacity before this item was added
    }
    reverse(selected.begin(), selected.end());

    cout << "Selected items: ";
    for (const auto& s : selected) cout << s << " ";
    cout << endl;

    // Complexity summary
    cout << endl;
    cout << "Time  complexity: O(nW)" << endl;
    cout << "Space complexity: O(W)  [1D array only]" << endl;
}


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

    // --- Part 1: 2D DP ---
    solve2D(names, weight, value, n, W);

    // --- Part 2: 1D optimized DP ---
    solve1D(names, weight, value, n, W);

    return 0;
}
