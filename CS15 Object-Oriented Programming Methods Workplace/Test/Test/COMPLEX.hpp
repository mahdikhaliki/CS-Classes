#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
class COMPLEX
{
public:
    COMPLEX();
    void Aread(istream &input);
    void Awrite(ostream& output);
    COMPLEX add(COMPLEX&);
    COMPLEX subtract( COMPLEX &);
    COMPLEX multiply( COMPLEX &);
    COMPLEX divide( COMPLEX &);
    double absoluteValue();
    void setR(); // these might not be void
    void getR();
    void setI();
    void getI();
    COMPLEX SandG();
    
    
private:
    double a,b;
};

#endif // COMPLEX_H
