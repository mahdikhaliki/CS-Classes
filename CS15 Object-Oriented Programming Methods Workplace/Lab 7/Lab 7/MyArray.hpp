//
//
//
// Keith Mehl
// 
//
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <iostream>

class MyArray {
private:
    int *_a;     // a holds the array of ints
    int _n;      // n is number of elements in array
public:
    MyArray();                         // default constructor
    MyArray( int num );                // normal constructor
    MyArray( const MyArray &m );       // copy constructor
    MyArray( MyArray &&m );            // move constructor, R-Value Reference
    ~MyArray();                        // destructor
    int &At( int pos );                // get value at position pos
    int &operator []( int pos );       // operator [], equivalent to At()
    int getSize() const;         // return number of elements in the array
    MyArray &operator =( MyArray &rhs ); // deep copy (copy assignment)
    MyArray &operator =( MyArray &&rhs ); // move assignment
};

#endif /* MyArray_hpp */
