#ifndef Square_hpp
#define Square_hpp

#include "Rectangle.hpp"

class Square : public Rectangle {
    friend istream &operator >>(istream &in, Square &p);
    friend ostream &operator <<(ostream &out, Square &p);
public:
    Square();
    virtual double area();
    virtual double perimeter();
    virtual void validate();
    void read(istream &in);
    virtual void print(ostream &out);
};

#endif /* Square_hpp */
