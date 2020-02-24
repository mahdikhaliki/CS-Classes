#include "Square.hpp"

Square::Square() {
    _a.setAll(4.0, 0.0);
    _b.setAll(0.0, 0.0);
    _c.setAll(0.0, 4.0);
    _d.setAll(4.0, 4.0);
}

double Square::area() {
    return _a.Distance(_b) * _a.Distance(_b);
}

double Square::perimeter() {
    return _a.Distance(_b) * 4;
}

void Square::validate() {
    Rectangle::validate();
    if (!Equals(_a.Distance(_b),  _b.Distance(_c))) {
        cout << "The points do not make a square." << endl;
        _a.setAll(5.0, 0.0);
        _b.setAll(0.0, 0.0);
        _c.setAll(0.0, 5.0);
        _d.setAll(5.0, 5.0);
        cout << "New points: " << _a << _b << _c << _d << endl;
    }
}

void Square::read(istream &in) {
    in >> _a >> _b >> _c >> _d;
    validate();
}

void Square::print(ostream &out) {
    cout << "This is a square." << endl;
    Rectangle::print(out);
}

istream &operator >>(istream &in, Square &p) {
    p.read(in);
    return in;
}

ostream &operator <<(ostream &out, Square &p) {
    p.print(out);
    return out;
}
