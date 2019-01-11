#ifndef SERVER_MATRIXDOMAIN_H
#define SERVER_MATRIXDOMAIN_H

#include "Searchable.h"
#include <iostream>

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
private:
    int x, y;
};

std::ostream& operator<<(std::ostream& os, const Point& obj);

class MatrixDomain : public Searchable<Point> {
public:
    MatrixDomain(int** matrix, int size, int startx, int starty, int endx, int endy);
    MatrixDomain(vector<string>& strings);
    ~MatrixDomain();
    virtual State<Point>* getInitialState();
    virtual State<Point>* getGoalState();
    virtual vector<State<Point>*> getAllPossibleStates(State<Point>* p);

private:
    int** matrix;
    int size;
    Point start, end;
};


#endif //SERVER_MATRIXDOMAIN_H
