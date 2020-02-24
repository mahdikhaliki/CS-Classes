//
// prime.cpp
//
// Mahdi Khaliki
// Assignment 9 part 2
// Prints out all prime numbers from 0 to 3000
// using Sieve of Eratosthenes algorithm.
//

#include <iostream>
#include <fstream>
using namespace std;

const int MAX = 3000;
const int lineMax = 7;

int main()
{
    int a[3001], i, j, ct = 0; // Declaring array and variables
    ofstream outPut("primeOutput.txt"); // Opening output file
    
    for (i = 0; i <= MAX; i++) // Marks all elements prime
    {
        a[i] = 1;
    }
    
    // Marking 0 and 1 to false.
    a[0] = 0;
    a[1] = 0;
    
    for (i = 2; i <= MAX / 2; i++) // Loops from element 2 to 1500
    {
        if (a[i] == 1) // If the element is prime
        {
            for (j = 2; j * i <= MAX; j++) // Marks all multiples to false
            {
                a[j * i] = 0;
            }
        }
    }
    
    for (i = 0; i <= MAX; i++) // Loops through all elements
    {
        if (a[i] == 1) // If element is prime
        {
            if (ct == 0) // If begining of line
            {
                outPut << i << flush;
            }
            else
            {
                outPut << '\t' << i << flush;
            }
            if (++ct == lineMax) // If end of line
            {
                ct = 0; // Reset count
                outPut << endl;
            }
        }
    }
    if (ct != 0) // If not at the begining of line
    {
        outPut << endl;
    }
    outPut.close();
    return 0;
}
