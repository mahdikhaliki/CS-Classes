#include "Pair.h"
#include <iostream>
using namespace std;

class Tester {
private:
    int k;
public:
    Tester(int k1 = 0) {
        k = k1;
    }
    int getVal() const {
        return k;
    }
    bool operator==(const Tester & other) const {
        return this->k == other.k;
    }
};

int main() {
    
    Pair<int> p1, p2(4, 5), p3(7);
    p1 = p3;
    if (p1 == p3)
        cout << "They are equal." << endl;
    cout << p1 << endl;
    
    Pair<Tester> myPair(12);
    cout << myPair.getFirst().getVal() << endl;
    if (myPair == myPair)
        cout << "Equal" << endl;
//    cout << myPair << endl;
    
    
    
    return 0;
}
