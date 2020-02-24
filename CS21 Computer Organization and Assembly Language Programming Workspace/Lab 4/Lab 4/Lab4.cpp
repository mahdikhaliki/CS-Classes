//
//  Farris Tang and Mahdi Khaliki
//  Lab 4
//  3/6/18
//

#include <iostream>
using namespace std;

void func1() {
        int a = 0;
        int b = 0;
        if( a <= b )
        {
                b = 10;
        }
        cout << "a = " <<  a << "\tb= " << b << endl;
}

void func2() {
        int a = 0;
        int b = 0;
        if( a < b )
        {
                b = 10;
        }
        else
        {
                a = 20;
        }
        cout << "a = " <<  a << "\tb= " << b << endl;
}

void func3() {
        int a, b;
        a = 0;
        b = 0;
        while( a < 10 )
        {
                b += a;
                a++;
        }
        cout << "a = " <<  a << "\tb= " << b << endl;
}

void func4() {
        int a = 0;
        int b = 0;
        do {
                b += a;
                a++;
        } while( a < 10 );
        cout << "a = " <<  a << "\tb= " << b << endl;
}

void func5() {
        int b = 0;
        int a;
        for( a = 0; a < 10; a++ )
        {
                b += a;
        }
        cout << "a = " <<  a << "\tb= " << b << endl;
}

int main() {
        cout << "Func1: " << flush;
        func1();
        cout << "Func2: " << flush;
        func2();
        cout << "Func3: " << flush;
        func3();
        cout << "Func4: " << flush;
        func4();
        cout << "Func5: " << flush;
        func5();
        return 0;
}

