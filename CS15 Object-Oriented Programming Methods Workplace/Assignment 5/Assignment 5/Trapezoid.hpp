#ifndef Trapezoid_hpp
#define Trapezoid_hpp

#include "Quadrilateral.hpp"

class Trapezoid : public Quadrilateral {
    friend istream &operator >>(istream &in, Trapezoid &p);
    friend ostream &operator <<(ostream &out, Trapezoid &p);
public:
    Trapezoid();
    double area();
    double perimeter();
    void validate();
    void read(istream &in);
    void print(ostream &out);
};

#endif /* Trapezoid_hpp */
