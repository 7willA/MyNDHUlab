#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Point
{
private:
    float x;
    float y;

public:
    Point() : x(0), y(0) {}
    Point(float a, float b) : x(a), y(b) {}

    void printPoint()
    {
        cout << "(" << x << ", " << y << ")";
    }

    float getX() { return x; }
    float setX(float c) { x = c; return x; }
    float getY() { return y; }
    float setY(float d) { y = d; return y; }

    float getDistance(Point e)
    {
        float dx = x - e.getX();
        float dy = y - e.getY();
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

    Point getPoint1() { return point1; }
    Point getPoint2() { return point2; }
};

class Shape
{
public:
    Shape() : edgeCount(0) {}

    Shape(Segment *segments, int count)
    {
        if (count > 10)
            throw invalid_argument("Too many segments");

        for (int i = 0; i < count; i++)
        {
            seg[i] = segments[i];
        }
        edgeCount = count;

        // Check if segments form a closed path
        for (int i = 0; i < edgeCount; i++)
        {
            Point endPoint = seg[i].getPoint2();
            Point nextStartPoint = seg[(i + 1) % edgeCount].getPoint1();
            if (endPoint.getX() != nextStartPoint.getX() || endPoint.getY() != nextStartPoint.getY())
            {
                throw invalid_argument("Segments do not form a closed path");
            }
        }
    }

    virtual float getArea() = 0;

    float getPerimeter()
    {
        float perimeter = 0;
        for (int i = 0; i < edgeCount; i++)
        {
            perimeter += seg[i].getLength();
        }
        return perimeter;
    }

    Segment &getSeg(int index)
    {
        return seg[index];
    }

private:
    Segment seg[10];
    int edgeCount;
};