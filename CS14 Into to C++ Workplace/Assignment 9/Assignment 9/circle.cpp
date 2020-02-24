//
// circle.cpp
//
// Mahdi Khaliki
// Assignment 9
// Takes in input values for radius from a file
// and calculates the diameter circumference and area.
//

#include <iostream>
#include <fstream>
using namespace std;

const double  pi = 3.141592653589793;
int CircleStats(double r, double &d, double &c, double &a);

int main()
{
    double r, d, c, a; // Declaring varibles
    ifstream inFile("infile.txt"); // Opening input file
    ofstream outFile("outfile.txt"); // Opening output file
    
    if (!inFile) // Testing to see if file opened
    {
        cout << "Error opening file." << endl;
        return -1;
    }
    outFile << "Radius\tDiameter\tCircumference\tArea\n" << flush; // Printing header
    
    while (!inFile.eof()) // While not at the end of the file
    {
        inFile >> r; // Input radius
        if (CircleStats(r, d, c, a) == -1) // If return value is -1
        {
            outFile << r << "\tInvalid input value.\n" << flush;
        }
        else
        {
            outFile << r << "\t" << d << "\t\t" << c << "\t\t" << a << endl;
        }
    }
    outFile.close(); // Close output
    inFile.close(); // Close input
    return 0;
}

int CircleStats(double r, double &d, double &c, double &a)
{
    if (r <= 0) // Test if radius is valid to calculate
    {
        return -1;
    }
    d = r * 2; // Calculate diameter
    c = 2 * pi * r; // Calculate circumference
    a = r * r * pi; // Calculate area
    return 0;
}
