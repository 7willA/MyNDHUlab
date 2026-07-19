#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point() : x(0), y(0) {}

    Point(float xVal, float yVal) : x(xVal), y(yVal) {}

    void printPoint()
    {
        cout << "(" << x << ", " << y << ")";
    }

    float getX() { return x; }
    void setX(float xVal) { x = xVal; }

    float getY() { return y; }
    void setY(float yVal) { y = yVal; }

    float getDistance(Point p)
    {
        float dx = x - p.getX();
        float dy = y - p.getY();
        return sqrt(dx * dx + dy * dy);
    }
};

class Segment
{
private:
    Point point1;
    Point point2;

public:
    Segment() : point1(Point()), point2(Point()) {}

    Segment(Point p1, Point p2) : point1(p1), point2(p2) {}

    float getLength()
    {
        return point1.getDistance(point2);
    }
};
