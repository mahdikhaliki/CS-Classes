//
// milesToKilometer.cpp
//
// Mahdi Khaliki
// 8/28/16
// Assignment 1
// Converts miles + feet to kilometers
//

#include <iostream>
using namespace std;

int main()
{
    int newMiles;
    float miles, feet, totalfeet, totalmeters, kilometers;
    
    cout << "Enter miles (fractional part will not be calculated): " << flush;
    cin >> miles;
    newMiles = static_cast<int>(miles);
    cout << "Enter feet: " << flush;
    cin >> feet;
    
    totalfeet = newMiles * 5280 + feet;
    totalmeters = totalfeet / 3.28;
    kilometers = totalmeters / 1000;
    
    if (newMiles <= 1)
    {
        cout << newMiles << " mile and " << feet << " feet is " << kilometers << " kilometers" <<endl;
    }
    else
    {
        cout << newMiles << " miles and " << feet << " feet is " << kilometers << " kilometers" <<endl;
    }
    return 0;
}
