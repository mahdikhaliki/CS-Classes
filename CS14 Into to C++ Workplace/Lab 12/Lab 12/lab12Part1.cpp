//
// lab12Part1.cpp
//
// Mahdi Khaliki
// Lab 12
// Gets 50 entries from user and prints the smallest, largest, sum, and average.
// Then prints the entries in order, in reverse order, and ascending order.
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int ARRAYSIZE = 50;
void Exchange (int &i, int &j);
void PrintArray(int *a, string order);

int main() {
    // Declaring variables
    int a[ARRAYSIZE], smallest, largest, sum = 0, i, j, smallestValue;
    float average;
    
    // Getting input values from user
    for (i = 0; i < ARRAYSIZE; i++) {
        cout << "Enter an integer: " << flush;
        cin >> a[i];
    }
    
    // Finding the smallest number
    smallest = a[0];
    for (i = 0; i < ARRAYSIZE - 1; i++) {
        if (smallest > a[i + 1]) {
            smallest = a[i + 1];
        }
    }
    cout << "Smallest = " << smallest << endl;
    
    // Finding the largest number
    largest = a[0];
    for (i = 0; i < ARRAYSIZE - 1; i++) {
        if (largest < a[i + 1]) {
            largest = a[i + 1];
        }
    }
    cout << "Largest = " << largest << endl;
    
    // Adding up array for sum
    for (i = 0; i < ARRAYSIZE; i++) {
        sum += a[i];
    }
    cout << "Sum = " << sum << endl;
    
    // Calculating the average
    average = static_cast<float>(sum) / ARRAYSIZE;
    cout << "Average = " << average << '\n' << endl;
    
    // Printing array in user entry order
    cout << "Printing user entries in order:\n" << flush;
    PrintArray(a, "Normal");
    
    // Printing array in reverse order
    cout << "\nPrinting user entries in reverse order:\n" << flush;
    PrintArray(a, "Reverse");
    
    // Using selection sort to sort in ascending order
    for (i = 0; i < ARRAYSIZE - 1; i++)
    {
        smallestValue = i;
        for (j = i + 1; j < ARRAYSIZE; j++)
        {
            if (a[smallestValue] > a[j])
            {
                smallestValue = j;
            }
        }
    Exchange(a[i], a[smallestValue]);
    }
    
    // Printing array
    cout << "\nPrinting user entries in ascending order:" << endl;
    PrintArray(a, "Normal");
    return 0;
}

void Exchange (int &i, int &j)
{
    int t = i;
    i = j;
    j = t;
    return;
}

void PrintArray(int *a, string order)
{
    int ct = 0, i;
    if (order == "Normal")
    {
        for (i = 0; i < ARRAYSIZE; i++)
        {
            if (ct == 0) {
                cout << a[i] << flush;
            }
            else {
                cout << setw(4) << a[i] << flush;
            }
            if (++ct == 10) {
                cout << endl;
                ct = 0;
            }
        }
    }
    if (order == "Reverse")
    {
        for (i = ARRAYSIZE - 1; i >= 0; i--)
        {
            if (ct == 0) {
                cout << a[i] << flush;
            }
            else {
                cout << setw(4) << a[i] << flush;
            }
            if (++ct == 10) {
                cout << endl;
                ct = 0;
            }
        }
    }
    if (ct != 0) {
        cout << endl;
    }
}
