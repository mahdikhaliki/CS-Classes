#ifndef Trapezoid_hpp
#define Trapezoid_hpp

#include "Quadrilateral.hpp"

class Trapezoid : public Quadrilateral {
    friend istream &operator >>(istream &in, Trapezoid &p);
    friend ostream &operator <<(ostream &out, Trapezoid &p);
public:
    Trapezoid();
    virtual double area();
    virtual double perimeter();
    virtual void validate();
    void read(istream &in);
    virtual void print(ostream &out);
};

#endif /* Trapezoid_hpp */
