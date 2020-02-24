#include "Counter.h"
#include <ctime>
#include <iostream>
#include <string>
using namespace std;


Counter factorial(Counter c) {
    if (c > Counter(9834)) {
        cout << "factorial: argument is too big. Setting to 9834.";
        c = Counter(9834);
    }
    Counter result = 1;
    while (c != 0)
        result *= c--;
    return result;
}


void testIncrement(Counter  val) {
    cout << endl << "Press Enter to start testIncrement. " ;
    cin.get();
    cout << "val = " << val << endl;
    cout <<"After three preincrements, val = " <<  ++(++(++val)) << endl;
    cout << "After three predecrements, val = " << --(--(--val)) << endl;
    cout << "val++ evaluates to " << val++ << endl;
    cout << "val is now " << val << endl;
    cout << "++--val = " << ++--val << endl;
    cout << "val-- evaluates to " << val-- << endl;
    cout << "val is now " << val << endl;
    Counter bound = 101;
    cout << "Incrementing..." << endl;
    for (Counter i = 0; i < bound; i++) {
        cout << ++val << "\t\t";
        cout << "val.numDigits = " << val.getNumDigits() << endl;
    }
    cout << "Decrementing..." << endl;
    for (Counter i = 0; i < bound+10; i++) {
        cout << --val << "\t\t";
        cout << "val.numDigits = " << val.getNumDigits() << endl;
    }
    cout << "val is now " << val << endl;
    cout << "incrementing 100001 times without output..." << endl;
    for (int i = 0; i <= 100000; i++) val++;
    cout << "val is now " << val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    cout << "Done testIncrement" << endl << endl;
    
    
}

void testSetVal(Counter val) {
    cout << endl << "Press Enter to start setVal. " ;
    cin.get();
    val.set("0");
    cout << "val =  " << val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    cout << "val-- = " << val-- << endl;
    cout << "val = " << val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    cout << "val++ = " << val++ << endl;
    cout << "val = " << val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    val.set(2147483647);
    cout << "val = " << val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    cout << "++val = " << ++val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    val.set("9999999999999999999999999999999999999999999999999999999999999999999");
    cout << "val = " << val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    cout << "++val = " << ++val << endl;
    cout << "val.numDigits is " << val.getNumDigits() << endl;
    cout << "Done setVal" << endl << endl;
}


string tf(bool b) {
    return b ? "true" : "false";
}

void compareHelper(const Counter & a, const Counter & b) {
    cout << a << " == " << b << " evaluates to " << tf(a == b) << endl;
    cout << a << " != " << b << " evaluates to " << tf(a != b) << endl;
    cout << a << " <= " << b << " evaluates to " << tf(a <= b) << endl;
    cout << a << " >= " << b << " evaluates to " << tf(a >= b) << endl;
    cout << a << " <  " << b << " evaluates to " << tf(a < b) << endl;
    cout << a << " >  " << b << " evaluates to " << tf(a > b) << endl;
}

void testCompare() {
    cout << "Press Enter to start testCompare. ";
    cin.get();
    Counter v1("99999999");
    Counter v2("100000000");
    Counter v3("100000001");
    Counter v4 = v1 + 1;
    compareHelper(v1, v2);
    compareHelper(v2, v3);
    compareHelper(v2, v4);
    cout << "End testCompare " << endl << endl;
}

void testAddition(Counter  val1) {
    cout << "Press Enter to start testAddition. ";
    cin.get();
    Counter val2 = 2, val3 = 3;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "val1 + val1 + val1 = " << val1 + val1 + val1 << endl;
    cout << "val1 = " << val1 << endl;
    cout << "(val1 += val2) += val3 = " << ((val1 += val2) += val3) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "val1 += (val2 += val3) = " << (val1 += (val2 += val3)) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    
    cout << "val1 *= val2 += val3 = " << (val1 *= val2 += val3) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "val1 *= (val2 += val3) = " << (val1 *= (val2 += val3)) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "val1.numDigits = " << val1.getNumDigits() << endl;
    cout << "val2.numDigits = " << val2.getNumDigits() << endl;
    cout << "val3.numDigits = " << val3.getNumDigits() << endl;
    cout << "How many iterations? ";
    int count;
    cin >> count; cin.ignore(1);
    val1 = 1;
    cout << "val1 = " << val1 << endl;
    for (int i = 0; i < count; i++) {
        val1 += val1;
        cout << val1 << "\t\t" << val1.getNumDigits() << endl;
    }
    
}

void testFactorial() {
    cout << "Start testFactorial" << endl;
    Counter c1;
    cout << "Enter the factorial argument: ";
    cin >> c1;
    int t = time(0);
    Counter c2 = factorial(c1);
    
    cout << "The factorial is " << c2 << "." << endl;
    cout << "The number of digits is " << c2.getNumDigits() << endl;
    cout << "Elapsed time = " << time(0) - t << " seconds. " << endl;
    cout << "Done testFactorial " << endl << endl;
}

int main() {
    Counter  d = 1;
    cout << "The current value of d is " << d << endl;
    cout << "Enter a new value for d: ";
    cin >> d;
    cin.ignore(1);
    cout << "The value of d is now " << d << endl;
    testIncrement(d);
    testSetVal(d);
    testAddition(d);
    testCompare();
    testFactorial();
    cout << "Done with all tests. " << endl;
    return 0;
}
