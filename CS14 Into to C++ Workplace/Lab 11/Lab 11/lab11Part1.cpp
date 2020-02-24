//
// lab11Part1.cpp
//
// Mahdi Khaliki and Farris Tang
// Lab 11 Part 1
// Asks user to enter name and price of a menu item and stores it into a struct,
// then prints it out using the struct.
//

#include <iostream>
#include <string>
using namespace std;

struct menuItem // Creating struct
{
    string item;
    float price;
};

void ReadItem(istream&, menuItem&);
void PrintItem(ostream&, menuItem);

int main()
{
    menuItem m; // Declaring struct
    ReadItem(cin, m);
    PrintItem(cout, m);
    return 0;
}

void ReadItem(istream &cin, menuItem &m) // Asking user for fields
{
    cout << "Enter menu item: " << flush;
    cin >> m.item;
    cout << "Enter price: " << flush;
    cin >> m.price;
}

void PrintItem(ostream &cout, menuItem m) // Printing fields
{
    cout << "Name of menu item is: " << m.item << endl;
    cout << "Price of item is: $" << m.price << endl;
}
