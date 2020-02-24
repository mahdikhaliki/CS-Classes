//
// Lab7.cpp
//
// Mahdi Khaliki, Farris Tang, Lawrence Chao
// Lab 7
// Code the programs from the lab.
//

#include <iostream>
using namespace std;

int main()
{
    // Problem 1
    cout << "Problem 1" << endl;
    {
        int i, n;
        cin >> n;
        
        for (i = 0; i < n; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    // 1a
    {
        int i, n;
        cin >> n;
        i = 0;
        
        while (i < n)
        {
            cout << i << " ";
            i++;
        }
        cout << endl;
    }
    
    // 1b
    {
        int i, n;
        cin >> n;
        i = 0;
        
        if (n > 0)
        {
            do
            {
                cout << i << " ";
                i++;
            } while (i < n);
        }
        cout << endl;
    }
    
    // Problem 2
    cout << "Problem 2" << endl;
    {
        int n;
        cin >> n;
        while (n > 0)
        {
            cout << n << " ";
            n /= 2;
        }
        cout << endl;
    }
    
    // 2a
    {
        int n;
        cin >> n;
        if (n > 0)
        {
            do
            {
                cout << n << " ";
                n /= 2;
            } while (n > 0);
        }
        cout << endl;
    }
    
    // 2b
    {
        int n;
        cin >> n;
        for (n = n; n > 0; n /=2)
        {
            cout << n << " ";
        }
        cout << endl;
    }
    
    // Problem 3
    cout << "Problem 3" << endl;
    {
        int i, n;
        cin >> n;
        i = 1;
        do
        {
            cout << i << " ";
            i *= 2;
        } while (i <= n);
        cout << endl;
    }
    
    // 3a
    {
        int i, n;
        cin >> n;
        i = 1;
        
        cout << i << " ";
        i *= 2;
        for (i = 2; i <= n; i *= 2)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    // 3b
    {
        int i, n;
        cin >> n;
        i = 1;
        cout << i << " ";
        i *= 2;
        while (i <= n)
        {
            cout << i << " ";
            i *=2;
        }
        cout << endl;
    }
    return 0;
}
