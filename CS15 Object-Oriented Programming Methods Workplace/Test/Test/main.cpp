#include "COMPLEX.hpp"
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
COMPLEX::COMPLEX()
{
    //ctor
};

void Aread(istream& input)
{
    // need to ingore the spaces and parens and , ( a, b )
    // skip 2 take take 1 skip 2 take 1 skip 3  take op skip 3 take 1 skip 2 take 1
    double trash, c,d;
    char op;
    input >> trash >> trash >> a >> trash >> trash >> b >> trash>> trash
    >> trash >> op;
    if(op == 'A')// if op == A do something
    {
        absoluteValue();
    }
    else //else take in the next numbers or maybe make have it make
    {    //Another class obj and run this loop again
        //this might be fucked up idk though
        trash>> trash >> trash >> c>> trash>> trash >> d;
        COMPLEX com2(c,d);
    }
}
void Awrite(ostream& output)
{
    //writes in form ( a + bi )
    char op;
    op =( (b > 0) : +?  - );
    output << "( " << a << " " << op << " "<< b<< " )" << endl;
}
COMPLEX add(COMPLEX &com2 )
{
    COMPLEX r;
    r.a = a + com2.a;
    r.b = b + com2.b;
    return r;
}
COMPLEX subtract( COMPLEX & com2)
{
    COMPLEX r;
    r.a = a - com2.a;
    r.b = b - com2.b;
    return r;
}
COMPLEX multiply( COMPLEX & com2)
{
    COMPLEX r; // do we want diff variables to store multi?
    r.a = a * com2.a - b * com2.b ;
    r.b = a * com2.b + com2.a * b ;  //(a*cñb*d, a*d+b*c)
    return r;
}
COMPLEX divide( COMPLEX &)
{
    //(a,b) / (c,d) = ( (a*c+b*d)/(c2+d2),(b*c+a*d)/(c2+d2) )
    COMPLEX r;
    r.a = (a * com2.a + b * com2.b) /(com2.a*com2.a+ com2.b*com2.b)
    r.b = (b*com2.a + a com2.d)/(com2.a*com2.a + com2.b*com2.b)
}
double absoluteValue()
{
    //(a2+b2)
    double abs;
    abs = sqrt(a*a +b*b);//something like this
    
}
void setR(double r)
{
    a = r;
}
void getR()
{
    return a;
}
void setI(double i)
{
    b = i;
}
void getI()
{
    return b;
}
COMPLEX SandG(double r, double i)
{
    COMPLEX c;
    a = r;
    b = i;
    c.a = r;
    c.b = i;
    return c;
}
