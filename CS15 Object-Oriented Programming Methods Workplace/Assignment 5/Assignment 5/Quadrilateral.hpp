#ifndef Quadrilateral_hpp
#define Quadrilateral_hpp

#include "Point.hpp"

class Quadrilateral {
    friend istream &operator >>(istream &in, Quadrilateral &p);
    friend ostream &operator <<(ostream &out, Quadrilateral &p);
protected:
    Point _a, _b, _c, _d; // Aggregating Point
public:
    Quadrilateral(); // Default constructor
    Point getA(); // Get methods
    Point getB();
    Point getC();
    Point getD();
    void setALL(Point a, Point b, Point c, Point d); // Set all for objects
    double area();
    double perimeter();
    void validate();
    void print(ostream &out);
    void read(istream &in);
};

#endif /* Quadrilateral_hpp */
