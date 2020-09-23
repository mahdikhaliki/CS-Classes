//
//  main.cpp
//  EXAM2
//
//  Created by Mahdi Khaliki on 5/8/17.
//  Copyright © 2017 Mahdi Khaliki. All rights reserved.
//

#include <iostream>
#include "Point.hpp"
#include "Circle.hpp"
#include "Cylinder.hpp"
#include "Operator++.hpp"
using namespace std;

// #1 iterator
int iSum(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=a[i];
    }
    return sum;
}
// #1 recursive
int rSum(int a[], int n) {
    int sum = a[--n];
    if (n == 0) {
        return sum;
    }
    return (sum + rSum(a, n));
}

// #2 Function Template
template <typename T> T smallest(T a, T b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main() {
    // #1
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, n = 5;
    cout << "iSum = " << iSum(a, n) << endl;
    cout << "rSum = " << rSum(a, n) << endl;
    
    // #2
    cout << "\nSmallest is: " << smallest(a[6], a[9]) << endl;
    
    // #3
    Point p(5, 6);
    p.setAll(1, 2);
    cout << "\ngetX: " << p.getX() << "\ngetY: " << p.getY() << '\n' << p << endl;
    
    // #4
    Circle c(3, 4, 6);
    c.setAll(9, 8, 7);
    cout << '\n' << c << endl;
    
    // #5
    Cylinder y(1, 2, 3, 4);
    cout << "\nVolume = " << y.getVolume() << "\nArea = " << y.getArea() << endl;
    cout << y << endl;
    
    // #6
    Int z(4), x(3);
    int r;
    cout << "\nz = " << z << "\nx = " << x << endl;
    Int s = z + x;
    cout << "z + x = " << s << endl;
    cout << "++z = " << ++z << endl;
    cout << "x++ = " << x++ << endl;
    cout << "x = " << x << endl;
    r = x;
    cout << "r = " << r << endl;
    return 0;
}
