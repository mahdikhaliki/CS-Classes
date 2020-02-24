//
// oddDigit.cpp
//
// Mahdi Khaliki
// Assignment 7
// Determines if a character is an odd digit.
//

#include <iostream>
using namespace std;

bool IsOddDigit(char);

int main()
{
    char ch;
    for (ch = '0'; ch <= '9'; ch++) // Looping for numbers 0-9
    {
        if (IsOddDigit(ch) == true)
        {
            cout << "The character " << ch << " is an odd digit." << endl;
        }
        else
        {
            cout << "The character " << ch << " is not an odd digit." << endl;
        }
    }
    
    for (ch = ']'; ch <= 'c'; ch++) // Looping for special characters and a,b, and c
    {
        if (IsOddDigit(ch) == true)
        {
            cout << "The character " << ch << " is an odd digit." << endl;
        }
        else
        {
            cout << "The character " << ch << " is not an odd digit." << endl;
        }
    }
    
    for (ch = '>'; ch <= 'C'; ch++) // Looping for special characters and A,B, and C
    {
        if (IsOddDigit(ch) == true)
        {
            cout << "The character " << ch << " is an odd digit." << endl;
        }
        else
        {
            cout << "The character " << ch << " is not an odd digit." << endl;
        }
    }
    return 0;
}

bool IsOddDigit(char ch)
{
    if (ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9') // If one of these characters then return true
    {
        return 1;
    }
    else // Else return false
    {
        return 0;
    }
}

