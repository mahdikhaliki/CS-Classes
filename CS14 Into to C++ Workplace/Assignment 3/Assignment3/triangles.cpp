//
// triangles.cpp
//
// Mahdi Khaliki
// 9/16/16
// Assignment 3
// Calculates if the sides of a given triangle form a right triangle.
//

#include <iostream>
using namespace std;

int main()
{
    //Decare varibles
    int sideA, sideB, sideC;
    bool test;
    
    // Get user input
    cout << "Enter side a: " << flush;
    cin >> sideA;
    cout << "Enter side b: " << flush;
    cin >> sideB;
    cout << "Enter side c: " << flush;
    cin >> sideC;
    
    // Square the input
    sideA = sideA * sideA;
    sideB = sideB * sideB;
    sideC = sideC * sideC;
    
    // Test for output
    if (sideA == sideB + sideC)
    {
        cout << "The sides form a right triangle." << endl;
        test = true;
    }
    
    if (sideB == sideA + sideC)
    {
        cout << "The sides form a right triangle." << endl;
        test = true;
    }
    
    if (sideC == sideA + sideB)
    {
        cout << "The sides form a right triangle." << endl;
        test = true;
    }
    
    if (test == false)
    {
        cout << "The sides do not form a right triangle." << endl;
    }
    return 0;
}
