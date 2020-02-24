//
// shapes.cpp
//
// Mahdi Khaliki
// Assignment 8
// Printing various shapes based on user input.
//

#include <iostream>
using namespace std;

// Function prototypes
int GetShape(void);
int GetRows(int shape);
void DrawShape(int shape, int rows);
int CalcSpaces(int shape, int rows, int cRow);
int CalcStars(int shape, int rows, int cRow);
void PrintChars(int n, char c);

int main()
{
    int shape = 0;
    while (shape != 6) // While shape does not equal 6 (exit)
    {
        shape = GetShape(); // Get shape from user.
        if (shape == 6) // If shape equals 6, break out of loop.
        {
            break;
        }
        int rows = GetRows(shape); // Get number of rows for shape.
        DrawShape(shape, rows); // Draw shape
    }
    return 0;
}

int GetShape(void)
{
    int shape;
    cout << "1-Hour glass\n2-Triangle\n3-Parallelogram\n"// Printing menu
    "4-Pyramid\n5-Diamond\n6-Quit" << endl;
    
    do // Get shape and return shape while it is between 1 and 6.
    {
    cout << "Enter the corresponding number of a shape: " << flush;
    cin >> shape;
    } while (shape < 1 || shape > 6);
    return shape;
}

int GetRows(int shape)
{
    int rows;
    // If shape is 1, 3 or 5 get rows using the following algorithm
    if (shape == 1 || shape == 3 || shape == 5)
    {
        do // Get number of rows from user (must be between 3-23)
        {
            cout << "Enter number of Rows (3-23): " << flush;
            cin >> rows;
        } while (rows < 3 || rows > 23);
        
        if (!(rows % 2)) // If even integer +1
        {
            rows++;
        }
    }
    else
    {
        do // Get number of rows from user (must be between 3-23)
        {
            cout << "Enter number of Rows (3-23): " << flush;
            cin >> rows;
        } while (rows < 3 || rows > 23);
    }
    return rows;
}

void DrawShape(int shape, int rows)
{
        int cRow, space, star;
        for (cRow = 1; cRow <= rows; cRow++) // Incrementing the current Row
        {
            space = CalcSpaces(shape, rows, cRow); // Calculating Spaces
            star = CalcStars(shape, rows, cRow); // Calculation Stars
            PrintChars(space, ' '); // Printing Spaces
            PrintChars(star, '*'); // Printing Stars
            cout << endl;
        }
}

int CalcSpaces(int shape, int rows, int cRow)
{
    int space;
    if (shape == 1) // If user selects hour glass use following space formula.
    {
        if (cRow <= (rows / 2) + 1) // If top half of hour glass (including middle row).
        {
            space = cRow - 1;
        }
        else // If bottom half of hour glass.
        {
            space = rows - cRow;
        }
    }
    else if (shape == 2) // If user selects triangle use following space formula.
    {
        space = 0;
    }
    else if (shape == 3) // If user selects parallelogram use following space formula.
    {
        if (cRow <= (rows / 2) + 1) // If top half of parallelogram (including middle row).
        {
            space = (rows / 2 + 1) - cRow;
        }
        else // If bottom half of parallelogram.
        {
            space = 0;
        }
    }
    else if (shape == 4) // If user selects pyramid use following space formula.
    {
        space = rows - cRow;
    }
    else if (shape == 5) // If user selects diamond use following space formula.
    {
        if (cRow <= (rows / 2) + 1) // If top half of Diamond (including middle row).
        {
            space = (rows / 2 + 1) - cRow;
        }
        else // If bottom half of Diamond.
        {
            space = (cRow - 1) - (rows / 2);
        }
    }
    return space;
}

int CalcStars(int shape, int rows, int cRow)
{
    int star;
    if (shape == 1) // If user selects hour glass use following star formula.
    {
        if (cRow <= (rows / 2) + 1) // If top half of hour glass (including middle row).
        {
            star = rows - (cRow * 2) + 2;
        }
        else // If bottom half of hour glass.
        {
            star = (cRow * 2) - rows;
        }
    }
    else if (shape == 2) // If user selects triangle use following star formula.
    {
        star = rows - cRow;
        star++;
    }
    else if (shape == 3) // If user selects parallelogram use following star formula.
    {
        if (cRow <= (rows / 2) + 1) // If top half of parallelogram (including middle row).
        {
            star = cRow;
        }
        else // If bottom half of parallelogram.
        {
            star = rows - cRow + 1;
        }
    }
    else if (shape == 4) // If user selects pyramid use following star formula.
    {
        star = (cRow * 2) - 1;
    }
    else if (shape == 5) // If user selects diamond use following star formula.
    {
        if (cRow <= (rows / 2) + 1) // If top half of diamond (including middle row).
        {
            star = cRow * 2 - 1;
        }
        else // If bottom half of diamond.
        {
            star = (rows * 2) - (cRow * 2 - 1);
        }
    }
     return star;
}

void PrintChars(int n, char c)
{
    int i;
    for (i = 0; i < n; i++) // Printing n amount of spaces and stars.
    {
        cout << c << flush;
    }
}






