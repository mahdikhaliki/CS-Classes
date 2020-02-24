//
// ShapeClient.cpp
//
// Mahdi Khaliki
// Assignment 5
// Reads the type of a shape and a set of point and determines if the points are
// the shape of that type.
//

#include <iostream>
#include <fstream>
#include "Square.hpp"
using namespace std;

int main() {
    // Declaring objects and variables
    Quadrilateral q;
    Trapezoid t;
    Parallelogram p;
    Rectangle r;
    Square s;
    char mark;
    ifstream in("quadInput.txt"); // Opeing input file
    if (!in) { // Checking if file open worked correctly
        cout << "Error opening file." << endl;
        return -1;
    }
    
    while (!in.eof()) { // Looping till end of file
        in >> mark;
        if (in.eof()) { // Checking for enf of file
            break;
        }
        switch (mark) { // Using the letter in the file for each case.
            case 'Q':
                in >> q; // extracting points
                // Printing points, area, and perimeter
                cout << q << "\nArea = " << q.area() << "\nPerimeter = "
                     << q.perimeter() << endl;
                break;
            case 'T':
                in >> t;
                cout << t << "\nArea = " << t.area() << "\nPerimeter = "
                << t.perimeter() << endl;
                break;
            case 'P':
                in >> p;
                cout << p << "\nArea = " << p.area() << "\nPerimeter = "
                << p.perimeter() << endl;
                break;
            case 'R':
                in >> r;
                cout << r << "\nArea = " << r.area() << "\nPerimeter = "
                << r.perimeter() << endl;
                break;
            case 'S':
                in >> s;
                cout << s << "\nArea = " << s.area() << "\nPerimeter = "
                << s.perimeter() << endl;
                break;
        }
        cout << "--------------------------------------------" << endl;
        
    }
    in.close();
    return 0;
}
