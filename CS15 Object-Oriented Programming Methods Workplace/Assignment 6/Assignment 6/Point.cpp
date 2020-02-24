#include "Point.hpp"
using namespace std;

Point::Point() { // Default constructor
    _x = _y = 0 ;
}

Point::Point(double xVal, double yVal) { // Normal constructor
    _x = xVal;
    _y = yVal;
}

const double Point::VERTICAL = pow(10, 100); // initializing varible

void Point::setAll( double xVal, double yVal ) {
    _x = xVal;
    _y = yVal;
}

double Point::Distance(Point &b) { // Distance between 2 points
    return sqrt((_x - b._x) * (_x - b._x) + (_y - b._y) * (_y - b._y));
}

double Point::Slope(Point &b) { // Slope of 2 points
    if (Equals(_x, b._x)) {
        return VERTICAL;
    }
    else {
        return (_y - b._y) / (_x - b._x);
    }
}

double Point::getX() { // Returns the _x coordinate of Point
    return _x;
}

double Point::getY() { // Returns the _y coordinate of Point
    return _y;
}

istream &operator >>(istream &in, Point &p) { // Extracts _x and _y from file
    char t;
    in >> t >> p._x >> t >> p._y >> t;
    return in;
}

ostream &operator <<(ostream &out, Point &p) { // Prints _x and _y to output
    out << '(' << p._x << ',' << p._y << ')' << flush;
    return out;
}

