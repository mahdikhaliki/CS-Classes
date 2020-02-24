#include "Quadrilateral.hpp"

Quadrilateral::Quadrilateral()  { // Default constructor
    _a.setAll(4.0, 0.0);
    _b.setAll(0.0, 1.0);
    _c.setAll(1.0, 5.0);
    _d.setAll(3.0, 5.0);
}

Point Quadrilateral::getA() { // Get methods
    return _a;
}
Point Quadrilateral::getB() {
    return _b;
}
Point Quadrilateral::getC() {
    return _c;
}
Point Quadrilateral::getD() {
    return _d;
}

void Quadrilateral::setALL(Point a, Point b, Point c, Point d) {
    _a = a;
    _b = b;
    _c = c;
    _d = d;
}

double Quadrilateral::area() { // Area method to return area value
    double s = ((_a.Distance(_b) + _b.Distance(_c) + _c.Distance(_a)) / 2);
    return sqrt(s * (s-_a.Distance(_b)) * (s-_b.Distance(_c)) * (s-_c.Distance(_a)))
    * 2;
}

double Quadrilateral::perimeter() { // Perimeter method to return perimeter value
    return _a.Distance(_b) + _b.Distance(_c) + _c.Distance(_d) +_d.Distance(_a);
}
// Validates if it's a quadrilateral then modifies the values if it's not.
void Quadrilateral::validate() {
    if (LoE(_a.getX(), _b.getX()) || GoE(_b.getY(), _c.getY()) ||
        GoE(_c.getX(), _d.getX()) || LoE(_d.getY(), _a.getY())) {
        cout << "The points do not make a quadrilateral." << endl;
        _a.setAll(4.0, 0.0);
        _b.setAll(0.0, 1.0);
        _c.setAll(1.0, 5.0);
        _d.setAll(3.0, 5.0);
        cout << "New points: " << _a << _b << _c << _d << endl;
    }
}

void Quadrilateral::read(istream &in) { // Reads each object and validates points
    in >> _a >> _b >> _c >> _d;
    validate();
}
// Prints a message to output stating it is a quadrilateral
void Quadrilateral::print(ostream &out) {
    cout << "This is a quadrilateral\n" << "Points: " << _a << _b << _c << _d
    << flush;
}

istream &operator >>(istream &in, Quadrilateral &p) { // Wrapper for read
    p.read(in);
    return in;
}

ostream &operator <<(ostream &out, Quadrilateral &p) { // Wrapper for print
    p.print(out);
    return out;
}
