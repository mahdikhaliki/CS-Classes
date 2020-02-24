//
// lab12Part2.cpp
//
// Mahdi Khaliki and Farris Tang
// Lab 12 Part 2
// Add a new sentinel which stops at the first non positive integer or the 50th
// entry.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ARRAYSIZE = 50;
void Exchange (int &i, int &j);
void PrintArray(string s, int a[], int entryCt);
void SelectionSort(int a[], int entryCt);

int main()
{
    // Declaring variables
    int a[ARRAYSIZE] = {0}, smallest, largest, sum = 0, entryCt = 0, i, s;
    float average;
    
    // Getting input from the user
    do
    {
        cout << "Enter an integer: " << flush;
        cin >> s;
        if (s > 0) // If the entry is greater than 0, store it into the array.
        {
            a[entryCt] = s;
        }
    } while (s > 0 && ++entryCt < ARRAYSIZE);
    

    if (a[0] <= 0) // Checking if the first number in the array is positive
    {
        cout << "No Statistics" << endl;
    }
    else
    {
        // Finding the smallest number
        smallest = a[0];
        for (i = 0; i < entryCt - 1; i++)
        {
            if (smallest > a[i + 1])
            {
                smallest = a[i + 1];
            }
        }
        cout << "Smallest = " << smallest << endl;
        
        // Finding the largest number
        largest = a[0];
        for (i = 0; i < entryCt - 1; i++)
        {
            if (largest < a[i + 1])
            {
                largest = a[i + 1];
            }
        }
        cout << "Largest = " << largest << endl;

        // Calculating sum
        for (i = 0; i < entryCt; i++)
        {
            sum += a[i];
        }
        cout << "Sum = " << sum << endl;
        
        // Calculating Average
        average = sum / static_cast<float>(entryCt);
        cout << "Average = " << average << '\n' << endl;
    
        // Printing array in order
        cout << "Printing user entries in order:\n" << flush;
        PrintArray("ordered", a, entryCt);
        
        // Printing array in reverse order
        cout << "\nPrinting user entries in reverse order:\n" << flush;
        PrintArray("reverse", a, entryCt);
        
        // Using selection sort to sort in ascending order
        SelectionSort(a, entryCt);
        
        // Printing array after sorting
        cout << "\nPrinting entries in ascending order:" << endl;
        PrintArray("ordered", a, entryCt);
        return 0;
    }
}

void Exchange (int &i, int &j)
{
    int t = i;
    i = j;
    j = t;
    return;
}

void PrintArray(string order, int a[], int entryCt)
{
    int count = 0, i;
    if (order == "ordered")
    {
        // Printing array in order
        for (i = 0; i < entryCt; i++)
        {
            if (count == 0)
            {
                cout << a[i] << flush;
            }
            else
            {
                cout << setw(3) << a[i] << flush;
            }
            if (++count == 10) {
                cout << endl;
                count = 0;
            }
        }
    }
    if (order == "reverse")
    {
        // Printing array in reverse order
        for (i = entryCt - 1; i >= 0; i--)
        {
            if (count == 0)
            {
                cout << a[i] << flush;
            }
            else
            {
                cout << setw(3) << a[i] << flush;
            }
            if (++count == 10)
            {
                cout << endl;
                count = 0;
            }
        }
    }
    if (count != 0)
    {
        cout << endl;
    }
}

void SelectionSort(int a[], int entryCt)
{
    int i, smallestValue, j;
    for (i = 0; i < entryCt - 1; i++)
    {
        smallestValue = i;
        for (j = i + 1; j < entryCt; j++)
        {
            if (a[smallestValue] > a[j])
            {
                smallestValue = j;
            }
        }
        Exchange(a[i], a[smallestValue]);
    }
}
