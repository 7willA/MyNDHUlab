#include <iostream>
using namespace std;

class Point {
public:
    double X, Y;
    void display() { cout << "(" << X << ", " << Y << ")\n"; }
};

int main() {
    int N;
    cin >> N;
    while (N--) {
        Point p;
        cin >> p.X >> p.Y;
        p.display();
    }
    return 0;
}