//
// lab11Part3.cpp
//
// Mahdi Khaliki and Farris Tang
// Lab 11 Part 3
// Uses a input file to display a menu for the user to select their items from,
// then prints a receipt.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct menuItem
{
    string item;
    float price;
};

const int ARRAYSIZE = 10; // Declaring a constant for the array size
void ReadItem(istream&, menuItem&);
void PrintItem(ostream&, menuItem);
void SelectItem(menuItem m[], int itemSelect[]);
void PrintReceipt(menuItem m[], int itemSelect[], ostream&);

int main()
{
    // Declaring array for items and setting all values to 0
    int i , itemSelect[ARRAYSIZE] = {0};
    menuItem m[ARRAYSIZE];
    
    ifstream menu("menu.txt"); // Opening input file
    if (!menu) // Checking if open failed
    {
        cout << "Error opening file." << endl;
        return -1;
    }
    
    for (i = 0; i < ARRAYSIZE; i++) // Storing values from file in an array
    {
        ReadItem(menu, m[i]);
        cout << i+1 << ". " << flush;
        PrintItem(cout, m[i]); // Printing menu
    }
    
    SelectItem(m, itemSelect); // User selects items from menu
    PrintReceipt(m, itemSelect, cout); // Printing receipt to console
    menu.close(); // Closing input file
    return 0;
}

// Pulls the data from menu and stores values into array m
void ReadItem(istream &menu, menuItem &m)
{
    menu >> m.item >> m.price;
}


void PrintItem(ostream &cout, menuItem m) // Prints the menu for the user
{
    cout << m.item << setw(3)
    << "$" << fixed << showpoint
    << setprecision(2) << m.price << endl;
}

void SelectItem(menuItem m[], int itemSelect[]) // Asks the user to select items
{
    cout << "\nEnter menu item number: " << endl;
    for (int i = 0; i < ARRAYSIZE; i++) // Loop to ask user for input 10 times
    {
        cin >> itemSelect[i]; // Storing user input into array itemSelect
        // Making sure input is in range
        while (itemSelect[i] < -1 || itemSelect[i] > 10)
        {
            cout << "Enter an item 1-10: " << flush;
            cin >> itemSelect[i];
        }
        
        if (itemSelect[i] == -1) // Breaking out of look if user enters -1
        {
            break;
        }
        
        for (int s = 0; s < i; s++) // Checking if entry is a repeat
        {
            for (int j = s + 1; j <= i; j++)
            {
                if (itemSelect[s] == itemSelect[j])
                {
                    cout << "You can only enter 1 of each item,"
                    " please re-enter: " << flush;
                    cin >> itemSelect[i];
                }
            }
        }
    }
}
// Printing receipt
void PrintReceipt(menuItem m[], int itemSelect[], ostream& cout)
{
    float sum = 0;
    int i, count = 0;
    cout << "\nCustomer receipt:" << endl;
    for (i = 0; i < ARRAYSIZE; i++) // Loop to go through each element
    {
        if (itemSelect[i] > 0) // Only printing items that are not 0
        {
            // Printing items from array m that have been selected by the user
            cout << m[itemSelect[i] - 1].item << setw(3) << '$'
            << m[itemSelect[i] - 1].price << endl;
            
            sum += m[itemSelect[i] - 1].price; // Adding up the total
            count++; // Adding to the count for items bought
        }
    }
    cout << "Number of items: " << count << endl;
    cout << fixed << showpoint << setprecision(2) << "total:" << setw(3) << '$'
    << sum << endl;
}
