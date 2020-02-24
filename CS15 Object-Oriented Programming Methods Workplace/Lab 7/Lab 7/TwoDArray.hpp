//
//  TwoDArray.hpp
//  Lab 7
//
//  Created by Mahdi Khaliki on 4/19/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#ifndef TwoDArray_hpp
#define TwoDArray_hpp

#include <iostream>
#include "MyArray.hpp"

class TwoDArray {
private:
    int _nRows, _nCols;
    MyArray **a;
public:
    TwoDArray();
    TwoDArray(int nRows, int nCols);
    ~TwoDArray();
    void setAll(int, int);
    MyArray &operator [](int pos);
};

#endif /* TwoDArray_hpp */
