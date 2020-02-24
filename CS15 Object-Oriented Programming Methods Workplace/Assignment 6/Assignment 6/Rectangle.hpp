#ifndef Rectangle_hpp
#define Rectangle_hpp

#include "Parallelogram.hpp"

class Rectangle : public Parallelogram {
    friend istream &operator >>(istream &in, Rectangle &p);
    friend ostream &operator <<(ostream &out, Rectangle &p);
public:
    Rectangle();
    virtual double area();
    virtual double perimeter();
    virtual void validate();
    void read(istream &in);
    virtual void print(ostream &out);
};

#endif /* Rectangle_hpp */
