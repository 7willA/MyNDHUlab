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

    float getX() { return x; }
    float getY() { return y; }
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
        float dx = point1.getX() - point2.getX();
        float dy = point1.getY() - point2.getY();
        return sqrt(dx * dx + dy * dy);
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

protected:
    Segment seg[10];
    int edgeCount;
};

class Rectangle : public Shape
{
public:
    Rectangle(Segment *segments) : Shape(segments, 4) {}

    float getArea() override
    {
        float length = seg[0].getLength();
        float width = seg[1].getLength();
        return length * width;
    }
};