//
//  Mahdi Khaliki
//  Assignment 2
//

#include <iostream>
#include "OList.h"
using namespace std;

template <typename T>
void printListInfo(OList<T> data) {
    cout << data << "\tSmallest: " << data.getSmallest() << "\tLargest: "
         << data.getBiggest() << "\tSize: " << data.getSize() << endl;
}

int main() {
    int a[6] = {1, 1, 2, 2, 6, 6}, b[6] = {6, 4, 3, 2, 0, -1}, c[5] = {15, 0, -1, 3, 1};
    string s[3] = {"chair", "table", "book"};
    OList<int> test1(a, 6), test2(b, 6), test3(c, 5), test6(test1);
    OList<string> test4(s, 3);
//    cout << test6 << endl;
//    test1.print();
    printListInfo(test1 + test2);
    printListInfo(test2);
//    printListInfo(test6);
    
    cout << test1 + test2 << endl;

//    printListInfo(test5);
//    test5.insert(-165);
//    printListInfo(test2);
//    printListInfo(test5);
//    cout << test2 << test2.getSmallest() << '\t' << test2.getBiggest() << endl;
//    cout << test3 << test3.getSmallest() << '\t' << test3.getBiggest() << endl;
//    cout << test4 << endl;
//    test1 = test2;
//    test2.clear();
//    cout << test2 << endl;
//    test3.clear();
//    cout << test3 << endl;
//    test1 = test2 + test2;
//    printListInfo(test1);
//    printListInfo(test2);
//    test2 += test2;
//    cout << (test1 += test1) << endl;
//    printListInfo(test2);

//    cout << test1.find(2) << endl;
//    test1.insert(35);
//    cout << test1 << test1.getSmallest() << '\t' << test1.getBiggest() << endl;
//    test1.remove(6);
//    printListInfo(test1);
//    test1.printBackwards();


    return 0;
}


