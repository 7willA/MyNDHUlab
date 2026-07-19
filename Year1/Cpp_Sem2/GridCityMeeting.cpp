#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Friend {
public:
    int street, avenue;
    Friend(int s, int a) : street(s), avenue(a) {}
};

class GridCity {
    int S, A, F;
    vector<Friend> friends;
public:
    GridCity(int s, int a, int f) : S(s), A(a), F(f) {}

    void addFriend(int street, int avenue) {
        friends.emplace_back(street, avenue);
    }

    pair<int, int> bestMeetingPoint() {
        vector<int> streets, avenues;
        for (const auto& fr : friends) {
            streets.push_back(fr.street);
            avenues.push_back(fr.avenue);
        }
        sort(streets.begin(), streets.end());
        sort(avenues.begin(), avenues.end());
        int medianIdx = (F - 1) / 2;
        int bestStreet = streets[medianIdx];
        int bestAvenue = avenues[medianIdx];
        return {bestStreet, bestAvenue};
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int S, A, F;
        cin >> S >> A >> F;
        GridCity city(S, A, F);
        for (int i = 0; i < F; ++i) {
            int s, a;
            cin >> s >> a;
            city.addFriend(s, a);
        }
        auto [street, avenue] = city.bestMeetingPoint();
        cout << "(Street: " << street << ", Avenue: " << avenue << ")\n";
    }
    return 0;
}