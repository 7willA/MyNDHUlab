#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

// Structure to represent one item
struct Item {
    string name;
    double weight;
    double value;
    double ratio; // value-to-weight ratio
};

int main() {
    // --- Input data ---
    vector<Item> items = {
        {"A", 6, 30, 0},
        {"B", 3, 14, 0},
        {"C", 4, 16, 0},
        {"D", 2,  9, 0}
    };
    double W = 10.0; // knapsack capacity

    // --- Step 1: Compute value-to-weight ratio for each item ---
    // ratio tells us how much value we gain per unit of weight used
    for (auto& item : items) {
        item.ratio = item.value / item.weight;
    }

    // --- Step 2: Sort by ratio in descending order ---
    // Items with a higher ratio should be considered first because
    // they give the most value per unit of weight we spend.
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio; // higher ratio comes first
    });

    // --- Display sorted order ---
    cout << "Items sorted by value/weight ratio (descending):" << endl;
    cout << left << setw(6) << "Item"
         << setw(8) << "Weight"
         << setw(8) << "Value"
         << setw(12) << "Ratio" << endl;
    cout << string(34, '-') << endl;
    for (const auto& item : items) {
        cout << left << setw(6) << item.name
             << setw(8) << item.weight
             << setw(8) << item.value
             << fixed << setprecision(2) << setw(12) << item.ratio << endl;
    }
    cout << endl;

    // --- Step 3: Greedy selection ---
    double remaining = W;   // remaining knapsack capacity
    double totalValue = 0;  // accumulated total value

    cout << "Selection process:" << endl;
    cout << string(60, '-') << endl;

    for (const auto& item : items) {
        if (remaining <= 0) break; // knapsack is full

        if (item.weight <= remaining) {
            // --- Case 1: The whole item fits ---
            // Take 100% of this item.
            double fraction = 1.0;
            double taken = item.value * fraction;
            totalValue += taken;
            remaining  -= item.weight;

            cout << "Take item " << item.name
                 << ": take " << fixed << setprecision(2) << fraction * 100 << "% (all)"
                 << " -> value gained = " << taken
                 << ", remaining capacity = " << remaining << endl;
        } else {
            // --- Case 2: Only a fraction fits ---
            // Take exactly as much as the remaining capacity allows.
            // fraction = remaining / item.weight  (0 < fraction < 1)
            double fraction = remaining / item.weight;
            double taken    = item.value * fraction;
            totalValue += taken;
            remaining   = 0;

            cout << "Take item " << item.name
                 << ": take " << fixed << setprecision(2) << fraction * 100 << "%"
                 << " -> value gained = " << fixed << setprecision(2) << taken
                 << ", remaining capacity = 0.00" << endl;
        }
    }

    // --- Step 4: Report final answer ---
    cout << endl;
    cout << "========================================" << endl;
    cout << "Maximum total value = " << fixed << setprecision(2) << totalValue << endl;
    cout << "========================================" << endl;

    /*
     * Time  complexity: O(n log n)  — dominated by the sorting step
     * Space complexity: O(n)        — storage for the items vector
     */

    return 0;
}
