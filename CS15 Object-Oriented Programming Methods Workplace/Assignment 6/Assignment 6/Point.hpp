#ifndef Point_hpp
#define Point_hpp

#include <iostream>
#include <cmath>
#include "Equals.hpp"
using namespace std;

class Point {
    friend istream &operator >>(istream &in, Point &p);
    friend ostream &operator <<(ostream &out, Point &p);
private:
    double _x, _y;
public:
    Point(); // Default constructor
    Point(double xVal, double yVal); // Normal constructor
    const static double VERTICAL; // Varible to be used for slope
    void setAll(double xVal, double yVal); // Set both _x and _y
    double Distance(Point &b); // Returns the distance between 2 points
    double Slope(Point &b); // Returns the slope between 2 points
    double getX(); // Returns _x coordinate of a point
    double getY(); // Returns _y coordinate of a point
};

#endif /* Point_hpp */
