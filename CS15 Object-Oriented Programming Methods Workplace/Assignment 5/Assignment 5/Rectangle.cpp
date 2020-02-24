#include "Rectangle.hpp"

Rectangle::Rectangle() {
    _a.setAll(3.0, 0.0);
    _b.setAll(0.0, 0.0);
    _c.setAll(0.0, 4.0);
    _d.setAll(3.0, 4.0);
}

double Rectangle::area() {
    return _a.Distance(_b) * _b.Distance(_c);
}

double Rectangle::perimeter() {
    return Parallelogram::perimeter();
}

void Rectangle::validate() {
    Parallelogram::validate();
    if (Equals(_b.Slope(_c), Point::VERTICAL) && Equals(_a.Slope(_b), 0)) {
        return;
    }
    else if (!Equals(_b.Slope(_c), (-1/_a.Slope(_b)))) {
        cout << "The points do not make a rectangle." << endl;
        _a.setAll(4.0, 0.0);
        _b.setAll(0.0, 0.0);
        _c.setAll(0.0, 5.0);
        _d.setAll(4.0, 5.0);
        cout << "New points: " << _a << _b << _c << _d << endl;
    }
}

void Rectangle::read(istream &in) {
    in >> _a >> _b >> _c >> _d;
    validate();
}

void Rectangle::print(ostream &out) {
    cout << "This is a rectangle." << endl;
    Parallelogram::print(out);
}

istream &operator >>(istream &in, Rectangle &p) {
    p.read(in);
    return in;
}

ostream &operator <<(ostream &out, Rectangle &p) {
    p.print(out);
    return out;
}
