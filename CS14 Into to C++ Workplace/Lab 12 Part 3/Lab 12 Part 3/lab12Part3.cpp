//
// lab12Part3.cpp
//
// Mahdi Khaliki and Farris Tang
// Lab 12 Part 3
// Building on part 2
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
    int a[ARRAYSIZE], smallest, largest, sum = 0, entryCt = 0, ct = 0, i, s;
    float average;
    
    // Get input from the user
    do
    {
        cout << "Enter and integer: " << flush;
        cin >> s;
        if (ct++ < ARRAYSIZE && s > 0)
        {
            a[entryCt] = s;
            entryCt++;
        }
    } while (s > 0);
    
    if (a[0] <= 0)
    {
        cout << "No Statistics" << endl;
    }
    else
    {
        // Finding smallest number
        smallest = a[0];
        for (i = 0; i < entryCt - 1; i++) {
            if (smallest > a[i + 1]) {
                smallest = a[i + 1];
            }
        }
        cout << "Smallest = " << smallest << endl;
        
        // Finding largest number
        largest = a[0];
        for (i = 0; i < entryCt - 1; i++) {
            if (largest < a[i + 1]) {
                largest = a[i + 1];
            }
        }
        cout << "Largest = " << largest << endl;
        
        // Calculating sum
        for (i = 0; i < entryCt; i++) {
            sum += a[i];
        }
        cout << "Sum = " << sum << endl;
        
        // Average
        average = sum / static_cast<float>(entryCt);
        cout << "Average = " << average << '\n' << endl;
        
        // Printing array in order
        cout << "Printing user entries in order:\n" << flush;
        PrintArray("ordered", a, entryCt);
        
        // Printing array in reverse order
        PrintArray("reverse", a, entryCt);
        
        // Selection sort
        SelectionSort(a, entryCt);
        
        // Printing array after sorting
        cout << "Sorting in ascending order:" << endl;
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
        for (i = 0; i < entryCt; i++) {
            if (count == 0) {
                cout << a[i] << flush;
            }
            else {
                cout << setw(4) << a[i] << flush;
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
        cout << "Printing user entries in reverse order:\n" << flush;
        for (i = entryCt - 1; i >= 0; i--) {
            if (count == 0) {
                cout << a[i] << flush;
            }
            else {
                cout << setw(4) << a[i] << flush;
            }
            if (++count == 10) {
                cout << endl;
                count = 0;
            }
        }
    }
    
    if (count != 0) {
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
