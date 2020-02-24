#ifndef Parallelogram_hpp
#define Parallelogram_hpp

#include "Trapezoid.hpp"

class Parallelogram : public Trapezoid {
    friend istream &operator >>(istream &in, Parallelogram &p);
    friend ostream &operator <<(ostream &out, Parallelogram &p);    
public:
    Parallelogram();
    double area();
    double perimeter();
    void validate();
    void read(istream &in);
    void print(ostream &out);
};

#endif /* Parallelogram_hpp */
