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
    virtual double area(); // Returns the area value
    virtual double perimeter(); // Returns the perimeter value
    virtual void validate(); // Validates if its a quadrilateral
    virtual void print(ostream &out); // Prints the Points of a quadrilateral
    void read(istream &in); // Reads the points of a Quadrilateral
};

#endif /* Quadrilateral_hpp */
