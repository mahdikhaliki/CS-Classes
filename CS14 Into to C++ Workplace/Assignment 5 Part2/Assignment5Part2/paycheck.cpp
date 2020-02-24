//
// paycheck.cpp
//
// Mahdi Khaliki
// Assignment 5 Part 2
// Gets an input (in days) and outputs the total pay.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // Declare the variables
    int cent = 1, days, dayCount = 1;
    float total;
    
    // Get number of days
    cout << "How many days? " << flush;
    cin >> days;
    
    while (dayCount <= days)
    {
        cout << "Pay for day " << dayCount << " = " << cent << endl;
        cent *= 2;
        dayCount++;
    }
    
    // Compensating for the int = 1;
    cent--;
    
    // Calculating the total
    total = static_cast<float>(cent) / 100;
    
    // Output
    cout << "Total pay: $" << fixed << setprecision(2) << total << endl;
}
