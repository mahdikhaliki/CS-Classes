#include "COMPLEX.h"
#include <iostream>
#include <cmath>
using namespace std;

COMPLEX::COMPLEX() { // Default constructor
    _r = _i = 0;
}

COMPLEX::COMPLEX(double r, double i) { // Normal Constructor
    _r = r;
    _i = i;
}
// Reads a complex from input. I Had to return a bool because .eof() was not
// working properly (was looping the last line twice).
bool COMPLEX::read(istream &in) {
    char t;
    in >> t >> _r >> t >> _i >> t;
    return t;
}

void COMPLEX::write(ostream &out) { // Write a complex to output
    char op = _i < 0 ? '-' : '+'; // Determine the correct operator to print
    out << "( " << _r << ' ' << op << ' '  << abs(_i) << "i )" << flush;
}

COMPLEX COMPLEX::add(COMPLEX &t2) { // Adding 2 complex
    COMPLEX t3;
    t3._r = _r + t2._r;
    t3._i = _i + t2._i;
    return t3;
}

COMPLEX COMPLEX::subtract(COMPLEX &t2) { // Subtracting 2 complex
    COMPLEX t3;
    t3._r = _r - t2._r;
    t3._i = _i - t2._i;
    return t3;
}

COMPLEX COMPLEX::multiply(COMPLEX &t2) { // Multiplying 2 complex
    COMPLEX t3;
    t3._r = (_r * t2._r) - (_i * t2._i);
    t3._i = (_r * t2._i) + (_i * t2._r);
    return t3;
}

COMPLEX COMPLEX::divide(COMPLEX &t2) { // Dividing 2 complex
    COMPLEX t3;
    t3._r = ((_r * t2._r) + (_i * t2._i)) / ((t2._r * t2._r) + (t2._i * t2._i));
    t3._i = ((_i * t2._r) - (_r * t2._i)) / ((t2._r * t2._r) + (t2._i * t2._i));
    return t3;
}

double COMPLEX::absoluteValue(void) { // Calculating absolute value of a complex
    return sqrt((_r * _r) + (_i * _i));
}

void COMPLEX::setR(double r) { // Setter for the real value
    _r = r;
}

void COMPLEX::setI(double i) { // Setter for the imaginary value
    _i = i;
}

double COMPLEX::getR(void) { // Getter for the real value
    return _r;
}

double COMPLEX::getI(void) { // Getter for the imaginary value
    return _i;
}
// Setter for both the real and imaginary values
void COMPLEX::setRI(double r, double i) {
    _r = r;
    _i = i;
}
