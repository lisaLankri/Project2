#ifndef SERVER_POINT_H
#define SERVER_POINT_H

#include <string>

using namespace std;

class Point
{
public:
    Point() : x(0), y(0) {}
    Point(int _x, int _y) : x(_x), y(_y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
    Point& operator=(Point&& other)
    {
        x = other.x;
        y = other.y;
        return *this;
    }
    bool operator==(const Point& p) const
    {
        return (x == p.x) && (y == p.y);
    }
    int getX() const { return x;}
    int getY() const { return y;}
    string toString() const;
    static Point fromString(string str);
private:
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& obj);


#endif //SERVER_POINT_H
