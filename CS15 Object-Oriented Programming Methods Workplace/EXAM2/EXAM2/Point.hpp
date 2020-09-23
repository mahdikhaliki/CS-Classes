#ifndef Point_hpp
#define Point_hpp

#include <iostream>
using namespace std;

class Point {
protected:
    double _x, _y;
public:
    Point(double x, double y);
    void setAll(double x, double y);
    double getX();
    double getY();
    friend ostream &operator <<(ostream &out, Point &p);
};
#endif /* Point_hpp */
