//
// ascii.cpp
//
// Mahdi Khaliki
// 9/27/16
// Assignemnt 5 Part 1
// Prints an ascii table.
//

#include <iostream>
using namespace std;

int main()
{
    // Declare varibles
    int count = 0;
    char one = ' ';
    
    while (one <= '~')
    {
        cout << (char) one << " " << flush;
        one++;
        count++;
        
        // Printing the last character on a line
        if (count == 15 || count == 30 || count == 45 ||
            count == 60 || count == 75 || count == 89)
        {
            cout << (char) one << flush;
            one++;
            cout << endl;
        }
    }
    return 0;
}
