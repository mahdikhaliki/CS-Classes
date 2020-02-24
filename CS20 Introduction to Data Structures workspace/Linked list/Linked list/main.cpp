#include "List.h"
#include <iostream>
using namespace std;
int main() {
    List<int> m;
    m.insertFirst(3);
    m.insertFirst(2);
    m.insertFirst(1);
    cout << m << endl;
    m.removeFirst();
    cout << m << endl;
    m.clear();
    cout << m << endl;
    m.removeFirst();
    cout << m << endl;
    m.insertFirst(5);
    cout << m << endl;
    return 0;
}
