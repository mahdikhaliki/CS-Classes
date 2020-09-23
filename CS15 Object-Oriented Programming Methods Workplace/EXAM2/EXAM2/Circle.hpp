#ifndef Circle_hpp
#define Circle_hpp

#include <iostream>
#include "Point.hpp"
using namespace std;

class Circle {
protected:
    Point center;
    double radius;
public:
    Circle(double x, double y, double r);
    void setAll(double x, double y, double r);
    double getArea();
    double getCircumference();
    friend ostream &operator <<(ostream &out, Circle &c);

};
#endif /* Circle_hpp */
