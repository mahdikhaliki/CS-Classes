//
// roots.cpp
//
// Mahdi Khaliki
// Assignment 1
// Take a series of coefficients and print out the roots or give appropriate
// error messages quadratic formula cannot be completed.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int readFile(double &a, double &b, double &c, istream &input);
int root(double a, double b, double c, double &r1, double &r2);
void printTable(int n, double a, double b, double c, double r1, double r2,
                ostream &output);
int main() {
    // Declaring variables
    char iName[100], oName[100];
    double a, b, c, r1, r2;
    int n;
    
    // Getting file names from user
    cout << "Please enter input file name: " << flush;
    cin >> iName;
    cout << "Please enter output file name: " << flush;
    cin >> oName;
    
    // Opening files and checking if open failed or not
    ifstream input (iName);
    ofstream output (oName);
    if (!input || !output) {
        cout << "Error opening files." << endl;
        return -1;
    }
    //Printing file names.
    output << "Input file name: " << iName << '\n' << "Output file name: "
    << oName << endl;
    
    // reading the values from each line untill the end of file
    while (!input.eof()) {
        if (readFile(a, b, c, input) == 1) { // If true then continue
            // Using return value(n) to print appropriate message
            n = root(a, b, c, r1, r2);
            printTable(n, a, b, c, r1, r2, output); // Passing n to print function
        }
        else { // Only error left is the incomplete data message
            printTable(1, a, b, c, r1, r2, output);
        }
    }
    input.close();
    output.close();
    return 0;
}

int readFile(double &a, double &b, double &c, istream &input) {
    input >> a >> b >> c; // Using input stream to extract data
    // If I've reached the eof after my last extraction return -1
    if (input.eof()) {
        return -1;
    }
    else {
        return 1; // All data is here
    }
}

int root(double a, double b, double c, double &r1, double &r2) {
    if (a == 0) { // No solution
        return -1;
    }
    else if (b*b-(4*a*c) < 0) { // Complex number
        return -2;
    }
    else { // calculate the 2 roots
        r1 = (-b + sqrt(b*b-(4*a*c))) / (2 * a);
        r2 = (-b - sqrt(b*b-(4*a*c))) / (2 * a);
        return 0;
    }
}

void printTable(int n, double a, double b, double c, double r1, double r2,
                ostream &output) {
    static int header = 0; // To tell if the header is printed once already
    if (header == 0) { // Printing legend
        output << "\nLegend:\n" << "The coefficients a, b and c of an expression"
        " of the form ax^2 + bx + c are listed below.\n" << "The 2 roots are"
        " listed under root 1 and root 2 if the\ncoefficients given can be"
        " calculated successfully.\n"<< endl;
        // Printing header
        output << left << setw(8) << 'a' << setw(8) << 'b' << setw(8) << 'c'
        << setw(12) << "root 1" << setw(12) << "root 2" << endl;
    }
    
    if (n == 0) { // If solutions exist
        output << left << setw(8) << a << setw(8) << b << setw(8) << c
        << setw(12) << r1 << setw(12) << r2 << endl;
    }
    else if (n == -1) { // No solutions
        output << "Not a quadratic and has no roots (a == 0)" << endl;
    }
    else if (n == -2) { // Complex number
        output << "Complex ((b^2-4ac) < 0)" << endl;
    }
    else { // Not enough numbers
        output << "Too few numbers." << endl;
    }
    header++;
}





