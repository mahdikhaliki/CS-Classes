//
// lab 9.cpp
//
// Timothy Russell khalikimahdi@gmail.com
// CSCI-14 Program lab 9
// October 25 2016
// function space and coffee shop bill composition, when to reference and when not
#include <iostream>
#include <iomanip>
using namespace std;
//get input force >=0
void PromptInput(int &bagel, int &coffee, int &danish);
//calculates the extended line amounts, subtotal, tax, and grand total of the bill
void SumBill(int bagel, int coffee, int danish, float &subtotal, float &tax, float &total,
             float &totalBagel, float &totalCoffee, float &totalDanish);
// calculates the extended line amounts, subtotal, tax, and grand total of the bill
void PrintBill(int bagel, int coffee, int danish, float subtotal, float tax, float total,
               float totalBagel, float totalCoffee, float totalDanish);
// Global constants fixed item pricing
const float PRICEPERBAGEL = 1.50f;
const float PRICEPERCOFFEE = 1.25f;
const float PRICEPERDANISH = 2.25f;
const float TAXRATE = 0.09f;

int main()
{
    int bagel=-1, coffee=-1, danish=-1;//default set for item index
    float totalBagel = 0.0f, totalCoffee = 0.0f, totalDanish =0.0f,
          subtotal=0.0f, tax=0.0f, total=0.0f; //default garbage washout
    //asks for input force greater than 0
    PromptInput(bagel, coffee, danish);
    SumBill(bagel, coffee, danish, subtotal, tax, total,
            totalBagel, totalCoffee, totalDanish);
    PrintBill(bagel, coffee, danish, subtotal, tax, total,
              totalBagel, totalCoffee, totalDanish);
    return 0;
}
void PromptInput(int &bagel, int &coffee, int &danish)
{
    while (bagel < 0)
    {
        cout << "Enter the number of purchased bagels: " << flush;
        cin >> bagel;
    }
    while (coffee < 0)
    {
        cout << "Enter the amount of purchased coffee: " << flush;
        cin >> coffee;
    }
    while (danish < 0)
    {
        cout << "Enter the amount of danish purchased: " << flush;
        cin >> danish;
    }
    return;
}
void SumBill(int bagel, int coffee, int danish, float &subtotal, float &tax,
             float &total, float &totalBagel, float &totalCoffee, float &totalDanish)
{
    totalBagel = (bagel * PRICEPERBAGEL);
    totalCoffee = (coffee * PRICEPERCOFFEE);
    totalDanish = (danish * PRICEPERDANISH);
    subtotal =  totalBagel + totalCoffee + totalDanish;
    tax = subtotal * TAXRATE;
    total = subtotal + tax;
    return;
}
void PrintBill(int bagel, int coffee, int danish, float subtotal, float tax,
               float total, float totalBagel, float totalCoffee, float totalDanish)
{
    cout << fixed << showpoint << setprecision(2)
         << "\nReasonable Name Coffee \nItem Quantity Price\nCoffee\t"
         << coffee << "\t$" << totalCoffee << "\nBagels\t" << bagel
         << "\t$" << totalBagel << "\nDanish\t" << danish
         << "\t$"<<  totalDanish <<endl;
    cout << "\nSub Total\t$" << subtotal << "\nTax\t\t$" << tax
         << "\nTotal\t\t$" << total << endl;
    return;
}
