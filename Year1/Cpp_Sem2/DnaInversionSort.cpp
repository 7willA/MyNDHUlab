#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct DNAString {
    string str;
    int originalIndex;
    int inversions;

    DNAString(string s, int idx) : str(s), originalIndex(idx) {
        inversions = calculateInversions();
    }

    int calculateInversions() {
        int inv = 0;
        for (int i = 0; i < str.size(); ++i) {
            for (int j = i + 1; j < str.size(); ++j) {
                if (str[i] > str[j]) {
                    inv++;
                }
            }
        }
        return inv;
    }
};

bool compareDNA(const DNAString &a, const DNAString &b) {
    if (a.inversions == b.inversions) {
        return a.originalIndex < b.originalIndex;
    }
    return a.inversions < b.inversions;
}

void solve() {
    int M;
    cin >> M;
    for (int dataset = 0; dataset < M; ++dataset) {
        if (dataset != 0) {
            cout << endl;
        }
        int n, m;
        cin >> n >> m;
        vector<DNAString> dnaStrings;
        for (int i = 0; i < m; ++i) {
            string s;
            cin >> s;
            dnaStrings.emplace_back(s, i);
        }
        sort(dnaStrings.begin(), dnaStrings.end(), compareDNA);
        for (const auto &ds : dnaStrings) {
            cout << ds.str << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}