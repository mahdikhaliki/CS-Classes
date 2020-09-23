#ifndef Operator___hpp
#define Operator___hpp

#include <iostream>
using namespace std;

class Int {
private:
    int _i;
public:
    Int(int = 0);
    Int operator +(Int rhs);
    Int operator ++();
    Int operator ++(int i);
    operator int();
    friend ostream &operator <<(ostream &out, Int &i);
};

#endif /* Operator___hpp */
