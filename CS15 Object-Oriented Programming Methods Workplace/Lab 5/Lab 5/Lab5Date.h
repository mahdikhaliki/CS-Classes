//
// Lab5Date.h
//
// 3/8/17
// Mahdi Khaliki, Maxwell McAllister
// CSCI 15 Lab 5
// Header file to define Date class
//

#include <iostream>
using namespace std;
#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
private:
    int year, month, day;
public:
    Date();
    Date(int y, int m, int d);
    // Checks validity then sets fields to given values
    void SetAll(int y, int m, int d);
    // Methods which return the value of a given field
    int GetYear();
    int GetMonth();
    int GetDay();
    // Methods to print contents of Date on which they are called
    void Print1( ostream& ); // format "12/25/09"
    void Print2( ostream& ); // format "December 25, 2009"
    void Print3( ostream& ); // format "25 December 2009"
    int Difference( Date& );
};

#endif
