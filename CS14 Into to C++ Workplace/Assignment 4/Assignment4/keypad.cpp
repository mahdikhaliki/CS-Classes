//
// keypad.cpp
//
// Mahdi Khaliki
// 9/25/16
// Assignment 4
// Corresponds a letter to a number on a keypad.
//

#include <iostream>
using namespace std;

int main()
{
    // Declare the varible
    char user;
    
    // Get input from user
    cout << "Enter a single capital letter and I will\ncorrespond it to a digit on a telephone keypad: " << flush;
    cin >> user;
    
    // Test for output
    if (user == 'A' || user == 'B' || user == 'C')
    {
        cout << "The character " << user << " corresponds to digit 2 on the keypad." << endl;
    }
    else if (user == 'D' || user == 'E' || user == 'F')
    {
        cout << "The character " << user << " corresponds to digit 3 on the keypad." << endl;
    }
    else if (user == 'G' || user == 'H' || user == 'I')
    {
        cout << "The character " << user << " corresponds to digit 4 on the keypad." << endl;
    }
    else if (user == 'J' || user == 'K' || user == 'L')
    {
        cout << "The character " << user << " corresponds to digit 5 on the keypad." << endl;
    }
    else if (user == 'M' || user == 'N' || user == 'O')
    {
        cout << "The character " << user << " corresponds to digit 6 on the keypad." << endl; //<< start using endl if it is the last statement
    }
    else if (user == 'P' || user == 'R' || user == 'S')
    {
        cout << "The character " << user << " corresponds to digit 7 on the keypad." << endl;
    }
    else if (user == 'T' || user == 'U' || user == 'V')
    {
        cout << "The character " << user << " corresponds to digit 8 on the keypad." << endl;
    }
    else if (user == 'W' || user == 'X' || user == 'Y')
    {
        cout << "The character " << user << " corresponds to digit 9 on the keypad." << endl;
    }
    else if (user == 'Q' || user == 'Z')
    {
        cout << "The character " << user << " doesn't correspond to any digit on the keypad." << endl;
    }
    else
    {
        cout << "The character " << user << " is not a capital letter." << endl;
    }
    return 0;
}
