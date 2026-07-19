#include <cmath>
#include <iostream>
using namespace std;

class Segment {
private:
    Point p1, p2;

public:
    Segment() {}
    Segment(Point p1, Point p2) : p1(p1), p2(p2) {}

    void set(Point p1, Point p2) {
        this->p1 = p1;
        this->p2= p2;
    }

    double distance() {
        double x = p2.getX() - p1.getX();
        double y = p2.getY() - p1.getY();
        return sqrt(pow(x, 2) + pow(y, 2));
    }
};

int main () {
int N; 
cin >> N;
Segment s[N];

for (int i=0; i<N; i++ ){
double x1, y1, x2, y2;
cin >> x1>>y1>>x2>>y2;

Point point_x, point_y;
point_x.setX(x1);
point_x.setY(y1);
point_y.setX(x2); 
point_y.setY(y2);

s[i].set(point_x, point_y);
cout << s[i].distance() << endl;
}
return 0;
}