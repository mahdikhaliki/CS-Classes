//
// mortgage.cpp
//
// Mahdi Khaliki
// 9/1/16
// Assignment 2
// Calculates monthly payment for a mortgage
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double amount, rate, years, payment;
    
    cout << "Enter loan amount: " << flush;
    cin >> amount;
    cout << "Enter annual interest rate (e.g., 0.035 for 3.5%): " << flush;
    cin >> rate;
    cout << "Enter number of years: " << flush;
    cin >> years;
    
    years = 12 * years;
    payment = pow(1 + rate/12, years) * amount * rate/12 / (pow(1 +rate/12, years) - 1);
    
    cout << showpoint << fixed
    << "The monthly payment is: "
    << setprecision(2) << payment << endl;
    return 0;
}
