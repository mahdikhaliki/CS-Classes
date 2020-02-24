//
// complexCalculator.cpp
//
// Mahdi Khaliki
// Assignment 4
// Extracts a complex number from a file, calculates the result based on the
// operator (by overloading the operators) and prints the complex numbers to
// a output file.
//

#include <iostream>
#include <fstream>
#include "COMPLEX.h"
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 3) { // Checking if user entered all arguments
        cout << "Missing arguments." << endl;
        return -1;
    }
    
    // Declaring objects and variables
    COMPLEX a, b, c;
    char op;
    ifstream in(argv[1]); // Opening input file
    ofstream out(argv[2]); // Opening output file
    if (!in || !out) { // Testing if file opens worked correctly
        cout << "Error opening files." << endl;
        return -2;
    }
    
    while(in >> a) { // While the read method does not hit the eof
        in >> op; // Get the operator
        if (op != 'A') { // If it's not an absolute calculation
            in >> b; // Read the next complex number
            switch (op) { // Perform operations based on the operator
                case '+':
                    c = a + b;
                    break;
                case '-':
                    c = a - b;
                    break;
                case '*':
                    c = a * b;
                    break;
                default:
                    c = a / b;
                    break;
            }
            out << a << ' ' << op << ' ' << b << " = " << c << endl;
        }
        else { // Perform absolute value calculations
            out << '|' << a << "| = " << a.absoluteValue() << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}
