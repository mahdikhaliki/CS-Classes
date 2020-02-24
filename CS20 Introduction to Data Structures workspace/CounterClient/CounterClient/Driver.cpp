//
//  Mahdi Khaliki
//  Driver.cpp
//
//  Created by Mahdi Khaliki on 8/22/17.
//

#include <iostream>
#include "Counter.h"
using namespace std;

string tf(bool b) {
    return b ? "true" : "false";
}

void boolTest() {
    Counter val1, val2;
    cout << "\nBoolean test\nEnter first number: " << flush;
    cin >> val1;
    cout << "Enter second number: " << flush;
    cin >> val2;
    cout << val1 << " == " << val2 << " evaluates to " << tf(val1 == val2) << endl;
    cout << val1 << " != " << val2 << " evaluates to " << tf(val1 != val2) << endl;
    cout << val1 << " <= " << val2 << " evaluates to " << tf(val1 <= val2) << endl;
    cout << val1 << " >= " << val2 << " evaluates to " << tf(val1 >= val2) << endl;
    cout << val1 << " <  " << val2 << " evaluates to " << tf(val1 < val2) << endl;
    cout << val1 << " >  " << val2 << " evaluates to " << tf(val1 > val2) << endl;
    
}

void incrementDecrementTest() {
    Counter val1;
    cout << "\nIncrement and decrement test\nEnter a number: " << flush;
    cin >> val1;
    cout << "++val1 = " << ++val1 << endl;
    cout << "val1++ = " << val1++ << endl;
    cout << "val1 = " << val1 << endl;
    cout << "Incrementing val1" << " 20 times" << endl;
    for (int i = 0; i < 20; i++) {
        cout << ++val1 << endl;
    }
    
    cout << "--val1 = " << --val1 << endl;
    cout << "\nval1-- = " << val1-- << endl;
    cout << "val1 = " << val1 << endl;
    cout << "Decrementing val1" << " 20 times" << endl;
    for (int i = 0; i < 20; i++) {
        cout << --val1 << endl;
    }
    
}

void additionSubtractionTest() {
    Counter val1, val2, val3;
    cout << "\nAddition and subtraction test\nEnter val1 value: " << flush;
    cin >> val1;
    cout << "Enter val2 value: " << flush;
    cin >> val2;
    cout << "Enter val3 value: " << flush;
    cin >> val3;
    
    cout << "\nval1 + val2 = " << val1 + val2 << endl;
    cout << "val1 + val2 + val3 = " << val1 + val2 + val3 << endl;
    cout << "val1 = " << val1 << endl;
    cout << "val1 += val2 = " << (val1 += val2) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "(val1 += val2) += val3 = " << ((val1 += val2) += val3) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "val1 += (val2 += val3) = " << (val1 += (val2 += val3)) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;

    cout << "\nval1 - val2 = " << val1 - val2 << endl;
    cout << "val2 - val1 = " << val2 - val1 << endl;
    cout << "val1 -= val2 = " << (val1 -= val2) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "(val1 -= val2) -= val3 = " << ((val1 -= val2) -= val3) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
    cout << "val1 -= (val2 -= val3) = " << (val1 -= (val2 -= val3)) << endl;
    cout << "val1, val2, val3 = " << val1 << ", " << val2 << ", " << val3 << endl;
}

void multiplicationTest() {
    Counter val1, val2;
    cout << "\nMultiplication test\nEnter val1 value: " << flush;
    cin >> val1;
    cout << "Enter val2 value: " << flush;
    cin >> val2;
    cout << "val1 * val2 = " << val1 * val2 << endl;
    cout << "val1, val2 = " << val1 << ", " << val2 << endl;
    cout << "val1 *= val2 = " << (val1 *= val2) << endl;
    cout << "val1, val2 = " << val1 << ", " << val2 << endl;
    

}

void factorial() {
    Counter fact;
    cout << "\nFactorial\nEnter factorial value: " << flush;
    cin >> fact;
    if (fact > Counter(9834)) {
        cout << "factorial: argument is too big. Setting to 9834." << endl;
        fact = Counter(9834);
    }
    Counter result = 1;
    while (fact != Counter("0")) {
        result *= fact--;
    }
    cout << "factorial = " << result << endl;
    cout << "The number of digits is " << result.getNumDigits() << endl;

}

int main() {
    int input;
    Counter val1 = 1;
    cout << "Current value of val1 is " << val1 << endl;
    cout << "Enter a new value for val1: " << flush;
    cin >> val1;
    cout << "val1 now equals to " << val1 << " and has " << val1.getNumDigits()
         << " digits"  << endl;
    do {
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "Select from one of the tests below(enter the corresponding number)";
        cout << "\n1. Boolean operators\n2. Increment and decrement operators"
             << "\n3. Addition and subtraction operators\n4. Multiplication"
             << " operator\n5. Factorial\nEnter 0 to exit: " << flush;
        cin >> input;
        cout << "-----------------------------------------------------------------" << endl;

        switch (input) {
            case 1:
                boolTest();
                break;
            case 2:
                incrementDecrementTest();
                break;
            case 3:
                additionSubtractionTest();
                break;
            case 4:
                multiplicationTest();
                break;
            case 5:
                factorial();
            default:
                break;
        }
    } while(input > 0 && input < 6);
    
    return 0;
}

