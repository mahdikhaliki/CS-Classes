#include "Parallelogram.hpp"

Parallelogram::Parallelogram() {
    _a.setAll(5.0, 0.0);
    _b.setAll(0.0, 0.0);
    _c.setAll(1.0, 6.0);
    _d.setAll(6.0, 6.0);
}

double Parallelogram::area() {
    return (_a.Distance(_b)) * (_c.getY() - _b.getY());
}

double Parallelogram::perimeter() {
    return (_a.Distance(_b) * 2) + (_b.Distance(_c) * 2);
}

void Parallelogram::validate() {
    Trapezoid::validate();
    if (!Equals(_b.Slope(_c), _a.Slope(_d)) || !Equals(_a.Slope(_b), _d.Slope(_c))) {
        cout << "The points do not make a parallelogram." << endl;
        _a.setAll(4.0, 0.0);
        _b.setAll(0.0, 0.0);
        _c.setAll(1.0, 5.0);
        _d.setAll(5.0, 5.0);
        cout << "New points: " << _a << _b << _c << _d << endl;
    }
}

void Parallelogram::read(istream &in) {
    in >> _a >> _b >> _c >> _d;
    validate();
}

void Parallelogram::print(ostream &out) {
    cout << "This is a parallelogram." << endl;
    Trapezoid::print(out);
}

istream &operator >>(istream &in, Parallelogram &p) {
    p.read(in);
    return in;
}

ostream &operator <<(ostream &out, Parallelogram &p) {
    p.print(out);
    return out;
}
