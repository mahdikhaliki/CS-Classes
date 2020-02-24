//
// ShapeClient.cpp
//
// Mahdi Khaliki
// Assignment 5
// Reads the type of a shape and a set of point and determines if the points are
// the shape of that type. Then prints the object (with its points), the area and
// perimeter of that object. This version prints the objects and its area and
// perimeter using direct access, references, and pointers.
//

#include <iostream>
#include "Square.hpp"
using namespace std;

void printRef(Quadrilateral &s) {
    cout << s << "\nArea = " << s.area()
    << "\nPerimeter = " << s.perimeter() << endl;
    cout << "---------------------------------" << endl;
}

void printPointer(Quadrilateral *s) {
    cout << *s << "\nArea = " << s->area()
    << "\nPerimeter = " << s->perimeter() << endl;
    cout << "---------------------------------" << endl;
}

int main() {
    // Declaring objects and variables
    Quadrilateral q;
    Trapezoid t;
    Parallelogram p;
    Rectangle r;
    Square s;
    // Array of pointers to each class object
    Quadrilateral *shape[5] = {&q, &t, &p, &r, &s};
    int i;
    // Accessing the shapes directly
    cout << "Directly accessing the shapes:\n" << q << "\nArea = " << q.area()
    << "\nPerimeter = " << q.perimeter() << endl;
    cout << "---------------------------------" << endl;
    cout << t << "\nArea = " << t.area()
    << "\nPerimeter = " << t.perimeter() << endl;
    cout << "---------------------------------" << endl;
    cout << p << "\nArea = " << p.area()
    << "\nPerimeter = " << p.perimeter() << endl;
    cout << "---------------------------------" << endl;
    cout<< r << "\nArea = " << r.area()
    << "\nPerimeter = " << r.perimeter() << endl;
    cout << "---------------------------------" << endl;
    cout << s << "\nArea = " << s.area()
    << "\nPerimeter = " << s.perimeter() <<  endl;
    cout << "---------------------------------\n" << endl;
    // Accessing the shapes using a reference
    cout << "Using a reference to access the shapes:" << endl;
    for (i = 0; i < 5; i++) {
        printRef(*shape[i]); // Dereferencing and passing into the function
    }
    // Accessing the shapes with a pointer
    cout << "\nUsing a pointer to access the shapes:" << endl;
    for (i = 0; i < 5; i++) {
        printPointer(shape[i]); // Passing the pointer into the function
    }
    return 0;
}
