#include "Circle.hpp"

Circle::Circle(double x, double y, double r) : center(x, y) {
    radius = r;
}

void Circle::setAll(double x, double y, double r) {
    center.setAll(x, y);
    radius = r;
}

double Circle::getArea() {
    return (3.14159 * (radius * radius));
}
 
double Circle::getCircumference() {
    return (2 * 3.14159 * radius);
}

ostream &operator <<(ostream &out, Circle &c) {
    out << c.center << ' ' << c.radius << flush;
    return out;
}
