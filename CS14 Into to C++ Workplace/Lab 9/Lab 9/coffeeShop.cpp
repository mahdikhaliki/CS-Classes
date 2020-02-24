//
// coffeeShop.cpp
//
// Mahdi Khaliki and Farris Tang
// Lab 9
// Taking in the number of items and printing a receipt accordingly.
//

#include <iostream>
#include <iomanip>
using namespace std;

// Declaring constants
const float coffee = 1.25;
const float bagle = 1.50;
const float danish = 2.25;

// Function prototypes
void UserInput(int &nCoffee, int &nBagle, int &nDanish);
void CalcReceipt(int nCoffee, int nBagle, int nDanish, float &coffeeTotal, float &bagleTotal,
                float &danishTotal, float &subTotal, float &tax, float &total);
void PrintReceipt(int nCoffee, int nBagle, int nDanish, float coffeeTotal, float bagleTotal,
                  float danishTotal, float subTotal, float tax, float total);

int main()
{
    // Declaring variables for input and output.
    int nCoffee, nBagle, nDanish;
    float coffeeTotal, bagleTotal, danishTotal, subTotal, tax, total;
    
    UserInput(nCoffee, nBagle, nDanish); // Get number of each item.
    CalcReceipt(nCoffee, nBagle, nDanish, coffeeTotal, bagleTotal, // Calculate receipt
               danishTotal, subTotal, tax, total);
    PrintReceipt(nCoffee, nBagle, nDanish, coffeeTotal, bagleTotal, // Print receipt
                 danishTotal, subTotal, tax, total);
    return 0;
}

void UserInput(int &nCoffee, int &nBagle, int &nDanish) // Changes values in RAM
{
    do // Get number of Coffees
    {
    cout << "Enter number of coffees: " << flush;
    cin >> nCoffee;
    } while (nCoffee < 0);
    
    do // Get number of Bagles
    {
        cout << "Enter number of bagles: " << flush;
        cin >> nBagle;
    } while (nBagle < 0);
    
    do // Get number of Danish
    {
        cout << "Enter number of danish: " << flush;
        cin >> nDanish;
    } while (nDanish < 0);
}

void CalcReceipt(int nCoffee, int nBagle, int nDanish,float &coffeeTotal, float &bagleTotal,
                float &danishTotal, float &subTotal, float &tax, float &total)
{
    coffeeTotal = coffee * nCoffee; // Constant coffee * number of coffees
    bagleTotal = bagle * nBagle; // Constant bagle * number of bagles
    danishTotal = danish * nDanish; // Constant danish * number of danish
    subTotal = coffeeTotal + bagleTotal + danishTotal; // Adding 3 above totals for subtotal
    tax = subTotal * .09; // Multiplying subTotal by .09 to find tax.
    total = tax + subTotal; // Adding tax and subTotal for total.
}

void PrintReceipt(int nCoffee, int nBagle, int nDanish, float coffeeTotal, float bagleTotal,
           float danishTotal, float subTotal, float tax, float total)
{
    // Printing receipt header and body in 3 columns
    cout << "\n\t CS Coffee Shop\nItem\tQuantity\tPrice\n" << endl
    << "Coffee\t\t" << nCoffee << "\t\t$" << fixed << setprecision(2) << coffeeTotal << endl
    << "Bagles\t\t" << nBagle << "\t\t$" << bagleTotal << endl
    << "Danish\t\t" << nDanish << "\t\t$" << danishTotal << endl
    << "\nSub Total\t\t\t$" << subTotal << endl
    << "\nTax\t\t\t\t\t$" << tax << endl
    << "\nTotal\t\t\t\t$" << total << endl;
}

