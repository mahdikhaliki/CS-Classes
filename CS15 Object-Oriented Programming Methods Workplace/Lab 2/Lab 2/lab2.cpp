//
// lab2.cpp
//
// Mahdi Khaliki and Brian Deitchman
// Lab 2
// Write tests to see if our conclusions are correct.
//

#include <iostream>
using namespace std;

int main()
{
    char str[100] = "This is a simple C-string";
    char *pstr = "This is a declaration of a pointer to a C-string";
    char *qstr = pstr;
    char *rstr = str;
    
    cout << "The address of str in RAM is: " << (void *)str << endl;
    cout << "The address of pstr in RAM is: " << (void *)pstr << endl;
    cout << "The address of qstr in RAM is: " << (void *)qstr << endl;
    cout << "The address of rstr in RAM is: " << (void *)rstr << endl;
    
    cout << "\nstr points to: " << str << endl;
    cout << "pstr points to: " << pstr << endl;
    cout << "qstr points to: " << qstr << endl;
    cout << "rstr points to: " <<rstr << endl;
    
    // 1
    cout << "\n#1:\n" << str << endl;
    str[10] = 100;
    cout << str <<'\n'<< endl;
    
    // 2
    // This will blow up the program
//    pstr[10] = 65;

    // 3
    cout << "#3:\n" << pstr << endl;
    pstr = "This is the new string";
    cout << pstr << '\n' << endl;
    
    // 4
    // Blows up the program
//    cout << str << endl;
//    str = "whats up";
//    cout << str << endl;

    // 5
    cout << "#5:\npstr: " << pstr << "\nqstr: " << qstr << endl;
    pstr = "Hello";
    cout << "\npstr: " << pstr << "\nqstr: " << qstr << endl;
    
    // 6
    // Blows up the program
//    str = "Goodbye";
    
    // 7
    cout << "\n#7:\n" << str << endl;
    rstr[5] = 65;
    cout << str << endl;
    
    // 8
    cout << "\n#8:\n" << rstr << endl;
    str[10] = 65;
    cout << rstr << endl;
    
    // 9
    cout << "\n#9:\n" << pstr<<'\t'<< *pstr<<'\t'<<(void *)pstr <<endl;
    return 0;
}
