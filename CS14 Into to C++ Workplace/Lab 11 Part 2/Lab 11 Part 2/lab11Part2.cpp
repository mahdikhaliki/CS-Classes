//
// lab11Part2.cpp
//
// Mahdi Khaliki and Farris Tang
// Lab 11 part 2
// Uses an input file for the items and price of items on a menu and creates a
// output file using the values of the input file to create a menu.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct menuItem // Creating struct
{
    string item;
    float price;
};

const int ARRAYSIZE = 10;
void ReadItem(istream&, menuItem&);
void PrintItem(ostream&, menuItem);

int main()
{
    int i;
    menuItem m[ARRAYSIZE]; // Declaring array of struct menuItem
    ifstream menu("menu.txt"); // Opening input file
    ofstream menuOutput("menuOutput.txt"); // Opening output file
    
    if (!menu || !menuOutput) // Checking if files opened
    {
        cout << "Error opening file." << endl;
        return -1;
    }
    
    for (i = 0; i < ARRAYSIZE; i++) // Looping to call the functions
    {
    ReadItem(menu, m[i]);
    PrintItem(menuOutput, m[i]);
    }
    menu.close();
    menuOutput.close();
    return 0;
}

void ReadItem(istream &menu, menuItem &m) // Pulling data from the input file
{
    menu >> m.item >> m.price;
}

void PrintItem(ostream &menuOutput, menuItem m) // Printing menu to output file
{
    menuOutput << "Name of menu item is: " << m.item << '\t'
    << "$" << fixed << showpoint
    << setprecision(2) << m.price << endl;
}
