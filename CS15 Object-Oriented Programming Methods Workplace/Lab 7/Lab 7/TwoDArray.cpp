//
//  TwoDArray.cpp
//  Lab 7
//
//  Created by Mahdi Khaliki on 4/19/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include <iostream>
#include "TwoDArray.hpp"
using namespace std;

TwoDArray::TwoDArray()
{
    int i;
    // new allocates RAM from system heap, [] says allocate an array
    
    _nRows = 10;
    a = new MyArray*[_nRows];
    
    for (i = 0; i < _nRows; i++)
    {
        a[i] = new MyArray;
    }
}
TwoDArray::TwoDArray(int nRows, int nCols)
{
    int i;
    // new allocates RAM from system heap, [] says allocate an array
    
    
    a = new MyArray*[nRows];
    
    _nCols = nCols;
    _nRows = nRows;
    
    for (i = 0; i < nRows; i++)
    {
        a[i] = new MyArray(nCols);
    }
}
void TwoDArray::setAll(int nRows, int nCols)
{
    _nCols = nCols;
    _nRows = nRows;
}
TwoDArray::~TwoDArray()
{
    int i;
    for (i = 0; i < _nRows; i++)
    {
        delete a[i];
    }
    delete[] a;
}
//MyArray &TwoDArray::operator [](int pos)
//{
//    if( pos < 0 || pos >= _nRows )
//    {
//        cout << "Illegal row index, pos = " << pos << endl;
//        exit( -1 );
//    }
//    return *a[pos];
//}

MyArray& TwoDArray ::operator[](int num)
{
    return *(a[num]);
}
