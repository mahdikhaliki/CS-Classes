//
// Mahdi Khaliki
//

#include "LetterBag.h"
#include <iostream>
#include <vector>
using namespace std;

void printBag(const LetterBag &bag)
{
    int frequency;
    for(char ch = 'a'; ch <= 'z'; ch++)
    {
        frequency = bag.getFrequency(ch);
        if (frequency > 0)
        {
            cout << ch << " : " << frequency << endl;
        }
    }
}

int main()
{
    LetterBag bag;
    LetterBag subbag;
    cout << "Testing vector parameter constructor... Adding characters now...\n";
    bag.add('b').add('a').add('c')  .add('b').add('a').add('c').  add('a');
    subbag.add('b').add('a');
    vector<char> vec = bag.toVector();
    vector<char> vect;
    vector<char> vecto = subbag.toVector();
    vect.push_back('a');
    vect.push_back('z');
    vect.push_back('d');
    vect.push_back('?');
    vect.push_back('e');
    vect.push_back('r');
    vect.push_back('r');
    vect.push_back('.');
    LetterBag bag2(vect);
    cout << "\nPrinting Vector\n";
    cout << "-----------------------------  ----------------\n";
    //    for (int i = 0; i < vec.size(); i++)
    //    {
    //        cout << vec[i] << " ";
    //    }
    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << " ";
    }
    cout << endl;
    //    printBag(bag);
    printBag(bag2);
    cout << endl;
    //    bag.remove('a');
    bag2.remove('a');
    cout << "Removed a\n";
    cout << "-----------------------------  ----------------\n";
    //    printBag(bag);
    printBag(bag2);
    cout << "Bag is set to clear\n\n";
    //    bag.clear();
    bag2.clear();
    cout << "This bag is Now: " << (bag2.isEmpty() ? "Empty" : "NOT EMPTY") << endl;
    cout << "-----------------------------  ----------------\n";
    cout << "Printing Bag to Ensure it's Empty\n";
    printBag(bag2);
    cout << "\nProgram Finished\n";
    
    cout << "\nTesting no parameter constructor... Adding characters now...\n";
    cout << "\nPrinting Vector\n";
    cout << "-----------------------------  ----------------\n";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    printBag(bag);
    cout << "\nSubBag contents: \n";
    printBag(subbag);
    cout << "\nSize of subbag: " << subbag.getCurrentSize() << endl;
    cout << "SubBag.isSubbag(bag) method returned " << (subbag.isSubbag(bag)) << endl;
    cout << "subbag == subbag returned " << (subbag == subbag) << endl;
    cout << "subbag != subbag returned " << (subbag != subbag) << endl;
    cout << "subbag != bag returned " << (subbag != bag) << endl;
    cout << "subbag == bag returned " << (subbag == bag) << endl;
    
    bag.remove('a');
    cout << "\nRemoved a from regular bag\n";
    cout << "-----------------------------  ----------------\n";
    printBag(bag);
    cout << "Bag is set to clear\n\n";
    bag.clear();
    cout << "This bag is Now: " << (bag.isEmpty() ? "Empty" : "NOT EMPTY") << endl;
    cout << "-----------------------------  ----------------\n";
    cout << "Printing Bag to Ensure it's Empty\n";
    printBag(bag);
    cout << "\nProgram Finished\n";
    return 0;
}
