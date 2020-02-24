#ifndef PAIR_H
#define PAIR_H
#include <iostream>
using namespace std;

template <class T>
class Pair {
    friend ostream& operator<< (ostream & out, const Pair<T> & p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }
private:
    T first, second;
    
public:
    Pair(const T & first = T(), const T & second = T()) {
        //  this->first = first;
        //  this->second = second;
        setFirst(first);
        setSecond(second);
    }
    
    T getFirst() const {
        return first;
    }
    T getSecond() const {
        return second;
    }
    void setFirst(const T & first) {
        this->first = first;
    }
    void setSecond(const T & second) {
        this->second = second;
    }
    
    void swap() {
        T temp = first;
        first = second;
        second = temp;
    }
    
    bool operator==(const Pair<T> & p) const {
        return this->first == p.first && this->second == p.second;
    }
    bool operator!=(const Pair<T> & p) const {
        return !(*this == p);  // or return !operator==(p);
    }
};
#endif
