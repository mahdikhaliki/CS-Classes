#include "Operator++.hpp"

Int::Int(int i) {
    _i = i;
}

Int Int::operator +(Int rhs) {
    Int result(_i + rhs._i);
    return result;
}

Int Int::operator++() {
    ++_i;
    return *this;
}

Int Int::operator++(int i) {
    Int t(_i);
    _i++;
    return t;
}

Int::operator int() {
    return _i;
}

ostream &operator <<(ostream &out, Int &i) {
    out << i._i << flush;
    return out;
}
