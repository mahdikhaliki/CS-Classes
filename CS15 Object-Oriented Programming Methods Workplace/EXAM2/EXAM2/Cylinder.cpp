#include "Cylinder.hpp"

Cylinder::Cylinder(double x, double y, double r, double h) : Circle(x,y,r) {
    height = h;
}

double Cylinder::getVolume() {
    return (Circle::getArea() * height);
}

double Cylinder::getArea() {
    return (Circle::getCircumference() * (height + radius));
}

ostream &operator <<(ostream &out, Cylinder &c) {
    out << dynamic_cast<Circle &>(c) << ' ' << c.height << flush;
    return out;
}
