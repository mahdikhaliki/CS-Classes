//
// Lab5Client2.cpp
//
// 3/23/17
// Mahdi Khaliki, Maxwell McAllister
// CS15 Lab 5
// Client of Date class, used to test Difference method
//
#include <iostream>
using namespace std;

#include "Lab5Date.h"

int main()
{
    // Local Date objects
    Date d1, d2;
    // Integers for input of dates, and difference
    int yIn, mIn, dIn, diff;
    // char to continue/exit loop
    char opt;
    
    cout << "Difference Client\nInput dates in format: year month day"
    << endl;
    // Loop to get two dates from user, and output difference
    do
    {
        // Prompt for dates
        cout << "Enter date 1: " << flush;
        cin >> yIn >> mIn >> dIn;
        // Set first date, which is the starting date
        d1.SetAll( yIn, mIn, dIn );
        cout << "Enter date 2: " << flush;
        cin >> yIn >> mIn >> dIn;
        d2.SetAll( yIn, mIn, dIn );
        // Calculate difference
        diff = d1.Difference( d2 );
        // Display the result, showing the dates as they exist
        cout << "Difference between " << flush;
        d1.Print3( cout );
        cout << " and " << flush;
        d2.Print3( cout );
        cout << " is:\n" << diff << " days." << endl;
        // Prompt user to continue or not
        cout << "Continue? (Y/N): " << flush;
        cin >> opt;
    } while( opt == 'Y' || opt == 'y' );
    return 0;
}
