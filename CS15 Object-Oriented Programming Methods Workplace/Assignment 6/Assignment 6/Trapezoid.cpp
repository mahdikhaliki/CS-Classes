#include "Trapezoid.hpp"
using namespace std;

Trapezoid::Trapezoid() {
    _a.setAll(4.0, 0.0);
    _b.setAll(0.0, 0.0);
    _c.setAll(1.0, 5.0);
    _d.setAll(3.0, 5.0);
}

double Trapezoid::area() {
    return ((_a.Distance(_b) + _c.Distance(_d)) / 2) * (_c.getY() - _b.getY());
}

double Trapezoid::perimeter() {
    return Quadrilateral::perimeter();
}

void Trapezoid::validate() {
    Quadrilateral::validate();
    if (!Equals(_a.Slope(_b), _d.Slope(_c)) && !Equals(_b.Slope(_c), _a.Slope(_d))) {
        cout << "The points do not make a trapezoid." << endl;
        _a.setAll(4.0, 0.0);
        _b.setAll(0.0, 0.0);
        _c.setAll(1.0, 5.0);
        _d.setAll(3.0, 5.0);
        cout << "New points: " << _a << _b << _c << _d << endl;
    }
}

void Trapezoid::read(istream &in) {
    in >> _a >> _b >> _c >> _d;
    validate();
}

void Trapezoid::print(ostream &out) {
    cout << "This is a trapezoid." << endl;
    Quadrilateral::print(out);
}

istream &operator >>(istream &in, Trapezoid &p) {
    p.read(in);
    return in;
}

ostream &operator <<(ostream &out, Trapezoid &p) {
    p.print(out);
    return out;
}
