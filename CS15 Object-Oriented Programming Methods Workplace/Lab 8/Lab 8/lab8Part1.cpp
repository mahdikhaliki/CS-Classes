//
// lab8Part1.cpp
//
// Mahdi Khaliki and Saoi Chan
// Lab 8 Part 1
// Creating funtion templates for absolute value, maximum(maxNum) and
// minimum(minNum) of 2 values, and maximum and minimum of 3 values. Then
// creating a few variables of various datatypes to test each template.
//

#include <iostream>
using namespace std;
// Template to find the absolute value of a number
template <typename T> T absolute(T a) {
    return a < 0 ? -a : a;
}
// Template to find the smaller value of 2 numbers
template <typename T> T minNum(T a, T b) {
    return a < b ? a : b;
}
// Template to find the larger value of 2 numbers
template <typename T> T maxNum(T a, T b) {
    return a > b ? a : b;
}
// Template to find the smaller value of 3 numbers
template <typename T> T minimum(T a, T b, T c) {
    T t = minNum(a, b);
    return c < t ? c : t;
}
// Template to find the largest value of 3 numbers
template <typename T> T maximum(T a, T b, T c) {
    T t = maxNum(a, b);
    return c > t ? c : t;
}
// Wrapper class around an int for testing purposes
class Int {
private:
    int _i;
public:
    Int() {
        _i = 0;
    }
    Int(int i) {
        _i = i;
    }
    bool operator <(Int &b) { // Operator < method to be used in comparison
        return _i < b._i ? true : false;
    }
    bool operator >(Int &b) { // Operator > method to be used in comparison
        return _i > b._i ? true : false;
    }
    // Prints the current state of the value
    friend ostream &operator <<(ostream &out, Int &i) {
        out << "Object value: " << i._i << flush;
        return out;
    }
};

int main() {
    double a[3] = {-1.34, 0, 8.999};
    int a1[3] = {-10, 0, 3};
    float a2[3] = {-4.53213, 0, 15.654};
    char first[10] = "Tom", last[10] = "Jenkins", middle[10] = "Abram";
    Int g(5), h(123), i(65), j = minNum(g, h), k = maxNum(g, h),
        l = minimum(g, h, i), m = maximum(g, h, i);
    // Testing absolute() with double, int and float.
    cout << "Absolute values of double datatype:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Original value: " << a[i] << endl;
        cout << "absolute() returned: " << absolute(a[i]) << endl;
    }
    
    cout << "\nAbsolute values of int datatype:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Original value: " << a1[i] << endl;
        cout << "absolute() returned: " << absolute(a1[i]) << endl;
    }
    
    cout << "\nAbsolute values of float datatype:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Original value: " << a2[i] << endl;
        cout << "absolute() returned: " << absolute(a2[i]) << endl;
    }
    // Testing minNum() with double, int, float, c++ string and an object.
    cout << "\nValues(double) passed into minNum(): " << a[0] << ", " << a[2]
         << "\nValue returned by minNum(): " << minNum(a[0], a[2]) << endl;
    
    cout << "\nValues(int) passed into minNum(): " << a1[0] << ", " << a1[1]
         << "\nValue returned by minNum(): " << minNum(a1[0], a1[1]) << endl;
    
    cout << "\nValues(float) passed into minNum(): " << a2[1] << ", " << a2[2]
         << "\nValue returned by minNum(): " << minNum(a2[1], a2[2]) << endl;
    
    cout << "\nValues(c++ string) passed into minNum(): " << first << ", " << last
         << "\nValue returned by minNum(): " << minNum(first, last) << endl;
    
    cout << "\nValues(objects) passed into minNum(): " << g << ", " << h
         << "\nValue returned by minimum(): " << j << endl;
    // Testing maxNum() with double, int, float, c++ string and an object.
    cout << "\nValues(double) passed into maxNum(): " << a[0] << ", " << a[2]
         << "\nValue returned by maxNum(): " << maxNum(a[0], a[2]) << endl;
    
    cout << "\nValues(int) passed into maxNum(): " << a1[0] << ", " << a1[1]
         << "\nValue returned by maxNum(): " << maxNum(a1[0], a1[1]) << endl;
    
    cout << "\nValues(float) passed into maxNum(): " << a2[1] << ", " << a2[2]
         << "\nValue returned by maxNum(): " << maxNum(a2[1], a2[2]) << endl;
    
    cout << "\nValues(c++ string) passed into maxNum(): " << first << ", " << last
         << "\nValue returned by maxNum(): " << maxNum(first, last) << endl;
    
    cout << "\nValues(objects) passed into maxNum(): " << g << ", " << h
         << "\nValue returned by maxNum(): " << k << endl;
    // Testing minimum() with double, int, float, c++ string and an object.
    cout << "\nValues(double) passed into minimum(): " << a[0] << ", " << a[2]
         << ", " << a[1] << "\nValue returned by minimum(): "
         << minimum(a[0], a[2], a[1]) << endl;
    
    cout << "\nValues(int) passed into minimum(): " << a1[0] << ", " << a1[1]
         << ", " << a1[2] << "\nValue returned by minimum(): "
         << minimum(a1[0], a1[1], a1[2]) << endl;
    
    cout << "\nValues(float) passed into minimum(): " << a2[1] << ", " << a2[2]
         << ", " << a2[0] << "\nValue returned by minimum(): "
         << minimum(a2[1], a2[2], a2[0]) << endl;
    
    cout << "\nValues(c++ string) passed into minimum(): " << first << ", "
         << middle << ", " << last << "\nValue returned by minimum(): "
         << minimum(first, middle, last) << endl;
    
    cout << "\nValues(objects) passed into minimum(): " << g << ", " << h
         << ", " << i << "\nValue returned by minimum(): " << l << endl;
    // Testing maximum() with double, int, float, c++ string and an object.
    cout << "\nValues(double) passed into maximum(): " << a[0] << ", " << a[2]
         << ", " << a[1] << "\nValue returned by maximum(): "
         << maximum(a[0], a[2], a[1]) << endl;
    
    cout << "\nValues(int) passed into maximum(): " << a1[0] << ", " << a1[1]
         << ", " << a1[2] << "\nValue returned by maximum(): "
         << maximum(a1[0], a1[1], a1[2]) << endl;
    
    cout << "\nValues(float) passed into maximum(): " << a2[1] << ", " << a2[2]
         << ", " << a2[0] << "\nValue returned by maximum(): "
         << maximum(a2[1], a2[2], a2[0]) << endl;
    
    cout << "\nValues(c++ string) passed into maximum(): " << first << ", "
         << middle << ", " << last << "\nValue returned by maximum(): "
         << maximum(first, middle, last) << endl;
    
    cout << "\nValues(objects) passed into maximum(): " << g << ", " << h
         << ", " << i << "\nValue returned by maximum(): " << m << endl;
    return 0;
}
