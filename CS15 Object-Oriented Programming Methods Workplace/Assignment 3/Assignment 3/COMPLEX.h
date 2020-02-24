#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class COMPLEX {
private:
    double _r, _i;
public:
    COMPLEX();
    COMPLEX(double r, double i);
    bool read(istream &in);
    void write(ostream &out);
    COMPLEX add(COMPLEX &t2);
    COMPLEX subtract(COMPLEX &t2);
    COMPLEX multiply(COMPLEX &t2);
    COMPLEX divide(COMPLEX &t2);
    double absoluteValue(void);
    void setR(double r);
    void setI(double i);
    double getR(void);
    double getI(void);
    void setRI(double r, double i);
};

#endif /* COMPLEX_H */
