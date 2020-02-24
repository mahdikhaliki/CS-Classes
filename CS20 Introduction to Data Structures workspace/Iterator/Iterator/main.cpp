#include "List.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList myList;
    myList.insertFirst(7);
    myList.insertFirst(6);
    myList.insertFirst(5);
    Iterator i = myList.begin();
    Iterator j = myList.end();
    cout << "Iterating through the list..." << endl;
    while (i != j) {
        cout << *i << " ";
        i++;
    }
    cout << endl;
    cout << "Data in *(myList.begin()) is " << *(myList.begin()) << endl;
    cout << "Inserting data in second position." << endl;
    myList.insertAfter(myList.begin(), 200);
    cout << "Data in *(myList.begin()+1) is " << *(myList.begin()+1) << endl;
    cout << "Iterating through the list..." << endl;
    for (Iterator k = myList.begin(); k != myList.end(); k++)
        cout << *k << " ";
    cout << endl;
    cout << "Changing the data in the second position to -3 " << endl;
    i = myList.begin() + 1;
    *i = -3;
    for (Iterator k = myList.begin(); k != myList.end(); k++)
        cout << *k << " ";
    cout << endl;
    
    return 0;
}
