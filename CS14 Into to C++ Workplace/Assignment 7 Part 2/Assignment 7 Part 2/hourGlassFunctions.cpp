//
// hourGlassFunctions.cpp
//
// Mahdi Khaliki
// Assignment 7 part 2
// Breaking the hour glass into functions.
//

#include <iostream>
using namespace std;

int GetRows(void);
void DrawShape(int);
int CalcSpaces(int, int);
int CalcStars(int, int);
void PrintChars(int, char);

int main()
{
    int rows = GetRows(); // Get the number of rows from user.
    DrawShape(rows); // Call DrawShape to draw the hour glass.
    return 0;
}

int GetRows(void) // Gets a legal entry from the user.
{
    int rows;
    do // Get number of rows from user
    {
        cout << "Enter number of rows (3-23 rows): " << flush;
        cin >> rows;
    } while (rows < 3 || rows > 23);
    
    if (!(rows % 2)) // If even integer then +1
    {
        rows++;
    }
    return rows;
}

void DrawShape(int rows) // Draws the hour glass based on number of rows.
{
    int cRow, space, star;
    for (cRow = 1; cRow <= rows; cRow++) // Increment the current row number.
    {
        space = CalcSpaces(rows, cRow); // Calculate spaces needed for current row.
        star = CalcStars(rows, cRow); // Calculate stars needed for current row.
        PrintChars(space, ' '); // Print spaces based on calculations.
        PrintChars(star, '*'); // Print stars based on calculations.
        cout << endl;
    }
}

int CalcSpaces(int rows, int cRow) // Calculates number of spaces for each line.
{
    int space;
    if (cRow <= (rows / 2) + 1) // If printing top half of hour glass (including middle row).
    {
        space = cRow - 1;
    }
    else // If printing bottom half of hour glass.
    {
        space = rows - cRow;
    }
    return space;
}

int CalcStars(int rows, int cRow) // Calculates number of stars for each line.
{
    int star;
    if (cRow <= (rows / 2) + 1) // If printing top half of hour glass (including middle row).
    {
        star = rows - (cRow * 2) + 2;
    }
    else // If printing bottom half of hour glass.
    {
        star = (cRow * 2) - rows;
    }
    return star;
}

void PrintChars (int n, char c) // Prints n amount of character c.
{
    int i;
    for (i = 0; i < n; i++) // Printing n amount of spaces or stars.
    {
        cout << c << flush;
    }
}
