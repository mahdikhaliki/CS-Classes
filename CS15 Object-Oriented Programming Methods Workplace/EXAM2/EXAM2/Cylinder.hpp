#ifndef Cylinder_hpp
#define Cylinder_hpp

#include <iostream>
#include "Circle.hpp"
using namespace std;

class Cylinder : public Circle {
private:
    double height;
public:
    Cylinder(double x, double y, double r, double h);
    double getVolume();
    double getArea();
    friend ostream &operator <<(ostream &out, Cylinder &c);
};

#endif /* Cylinder_hpp */
