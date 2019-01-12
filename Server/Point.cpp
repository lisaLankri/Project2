#include "Point.h"
#include "Utils.h"
#include <iostream>

using namespace std;

string Point::toString() const
{
    return std::to_string(x) + "," + std::to_string(y);
}

Point Point::fromString(string str)
{
    vector<string> numbers;
    Utils::tokenize(str, numbers, ",");
    Point p;
    p.x = std::stoi(numbers[0]);
    p.y = std::stoi(numbers[1]);
    return p;
}

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
    os << obj.getX() << "," << obj.getY();
    return os;
}
