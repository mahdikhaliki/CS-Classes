//
// hourGlass.cpp
//
// Mahdi Khaliki
// Assignment 6
// Prints an hour glass based on the number of rows.
//

#include <iostream>
using namespace std;

int main()
{
    // Declare variables
    int rows, cRow, space, star, s, i;
    
    // Get number of rows from user
    do
    {
        cout << "Enter number of rows (3-23 rows): " << flush;
        cin >> rows;
    } while (rows < 3 || rows > 23);
    
    // If even integer then +1
    if (!(rows % 2))
    {
        rows++;
    }
    
    for (cRow = 1; cRow <= rows; cRow++)
    {
        // Calculation for spaces and stars
        if (cRow <= (rows / 2) + 1)
        {
            space = cRow - 1;
            star = rows - (cRow * 2) + 2;
        }
        else
        {
            space = rows - cRow;
            star = (cRow * 2) - rows;
        }
        
        // Printing spaces
        for (s = 0; s < space; s++)
        {
            cout << " " << flush;
        }
        
        // Printing stars
        for (i = 0; i < star; i++)
        {
            cout << "*" << flush;
        }
        cout << endl;
    }
    return 0;
}
