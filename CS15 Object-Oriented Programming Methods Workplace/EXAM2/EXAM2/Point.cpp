#include "Point.hpp"

Point::Point(double x, double y) {
    setAll(x, y);
}

void Point::setAll(double x, double y) {
    _x = x;
    _y = y;
}

double Point::getX() {
    return _x;
}

double Point::getY() {
    return _y;
}

ostream &operator <<(ostream &out, Point &p) {
    out << "( " << p._x << ", " << p._y << " )" << flush;
    return out;
}
