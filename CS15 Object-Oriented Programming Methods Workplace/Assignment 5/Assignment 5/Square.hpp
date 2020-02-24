#ifndef Square_hpp
#define Square_hpp

#include "Rectangle.hpp"

class Square : public Rectangle {
    friend istream &operator >>(istream &in, Square &p);
    friend ostream &operator <<(ostream &out, Square &p);
public:
    Square();
    double area();
    double perimeter();
    void validate();
    void read(istream &in);
    void print(ostream &out);
};

#endif /* Square_hpp */
