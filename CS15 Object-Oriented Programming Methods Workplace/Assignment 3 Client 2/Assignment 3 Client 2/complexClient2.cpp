//
// complexClient2.cpp
//
// Mahdi Khaliki
// Assignment 3
// Client program to test the normal constuctor, setter and getter methods.
//

#include <iostream>
#include <fstream>
#include "COMPLEX.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) { // Checking if user entered all arguments
        cout << "Missing arguments." << endl;
        return -1;
    }
    COMPLEX s1(3.5, 1);
    ofstream out(argv[1]); // Opening output file
    if (!out) { // Testing if file opens worked correctly
        cout << "Error opening files." << endl;
        return -2;
    }
    // Printing values from normal constructor
    out << "Normal constructor:" << endl;
    s1.write(out);
    // Setting real value to 5.5 and printing to output
    out << "\n\nSetter for real value:" << endl;
    s1.setR(5.5);
    s1.write(out);
    // Setting imaginary value to 9.45 and printing to output
    out << "\n\nSetter for imaginary value:" << endl;
    s1.setI(9.45);
    s1.write(out);
    // Getting both real and imaginary and printing to output
    out << "\n\nGetter:\nReal = " << s1.getR() << '\t' << "Imaginary = " <<
    s1.getI() << endl;
    // Setting both real and imaginary simultaneously and printing to output
    out << "\nSetter for both real and imaginary values:" << endl;
    s1.setRI(26.457, 99.99);
    s1.write(out);
    out << endl;
    out.close();
    return 0;
}
