//
// complexCalculator.cpp
//
// Mahdi Khaliki
// Assignment 3
// Extracts a complex number from a file, calculates the result based on the
// operator and prints the complex numbers to a output file.
//

#include <iostream>
#include <fstream>
#include "COMPLEX.h"
using namespace std;
// Function prototype
void output(class COMPLEX t1, class COMPLEX t2, class COMPLEX t3, ostream &out,
            char op);

int main(int argc, char *argv[]) {
    if (argc < 3) { // Checking if user entered all arguments
        cout << "Missing arguments." << endl;
        return -1;
    }
    // Declaring objects and variables
    COMPLEX t1, t2, t3;
    char op;
    ifstream in(argv[1]); // Opening input file
    ofstream out(argv[2]); // Opening output file
    if (!in || !out) { // Testing if file opens worked correctly
        cout << "Error opening files." << endl;
        return -2;
    }
    while(t1.read(in)) { // While the read method does not hit the eof
        in >> op; // Get the operator
        if (op != 'A') { // If it's not an absolute calculation
            t2.read(in); // Read the next complex number
            switch (op) { // Perform operations based on the operator
                case '+':
                    t3 = t1.add(t2);
                    break;
                case '-':
                    t3 = t1.subtract(t2);
                    break;
                case '*':
                    t3 = t1.multiply(t2);
                    break;
                default:
                    t3 = t1.divide(t2);
                    break;
            }
            output(t1, t2, t3, out, op); // Output the t1, t2, and t3
        }
        else { // Perform absolute value calculations
            out << '|' << flush;
            t1.write(out);
            out << "| = " << t1.absoluteValue() << endl;
        }
    }
    in.close();
    out.close();
    return 0;
}
// Prints output in a reasonable format 
void output(class COMPLEX t1, class COMPLEX t2, class COMPLEX t3, ostream &out,
            char op) {
    t1.write(out);
    out << ' ' << op << ' ' << flush;
    t2.write(out);
    out << " = " << flush;
    t3.write(out);
    out << endl;
}
